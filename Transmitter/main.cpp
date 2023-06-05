#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

RF24 radio(9, 10);

const uint64_t pipe = 0xE8E8F0F0E1LL;

const int button = 3;
const int buzzer = 2;
const int green_led = 4;

bool pressed = false;

void setup()
{
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(green_led, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
}

void loop()
{
  if (digitalRead(button) == LOW)
  {
    pressed = true;
    int cnt = 0;
    int len = 0;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Enter message:");
    display.display();
    delay(1000);
    String message = "";
    while (pressed)
    {
      int dot_time = 250;
      int dash_time = dot_time * 3;
      int letter_space_time = dot_time * 3;
      int word_space_time = dot_time * 7;
      int pause_time = 100;
      int current_time = 0;
      bool button_state = digitalRead(button);
      if (button_state == HIGH)
      {
        digitalWrite(green_led, HIGH);
        tone(buzzer, 1000, dot_time);
        delay(dot_time);
        noTone(buzzer);
        message += ".";
        cnt++;
      }
      else
      {
        digitalWrite(green_led, HIGH);
        tone(buzzer, 1000, dash_time);
        delay(dash_time);
        noTone(buzzer);
        message += "-";
        cnt++;
      }
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print(message);
      display.display();
      delay(pause_time);

      if (cnt > 3)
      {
        pressed = false;
      }
    }
    digitalWrite(green_led, LOW);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Sending...");
    display.display();
    radio.begin();
    radio.openWritingPipe(pipe);
    radio.write(message.c_str(), message.length() + 1);
    radio.stopListening();
    delay(1000);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Sent message:");
    display.setCursor(0, 16);
    display.print(message);
    display.display();
    delay(3000);
  }
}
