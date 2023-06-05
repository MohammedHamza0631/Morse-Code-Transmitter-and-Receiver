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

const int red_led = 4;

String message = "";
void decode_morse();
char decode_letter(String morse_code);

void setup()
{
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    char buffer[32] = {0};
    radio.read(buffer, sizeof(buffer));
    message = buffer;
    digitalWrite(red_led, HIGH);
    delay(1000);
    digitalWrite(red_led, LOW);
    decode_morse();
    message = "";
  }
}

void decode_morse()
{
  String decoded_message = "";
  String current_letter = "";
  int dot_time = 250;
  int dash_time = dot_time * 3;
  int letter_space_time = dot_time * 3;
  int word_space_time = dot_time * 7;
  int pause_time = 50;
  for (int i = 0; i < message.length(); i++)
  {
    char current_char = message.charAt(i);
    if (current_char == '.')
    {
      current_letter += ".";
      delay(dot_time);
    }
    else if (current_char == '-')
    {
      current_letter += "-";
      delay(dash_time);
    }
    else if (current_char == ' ')
    {
      if (current_letter == "")
      {
        delay(word_space_time - pause_time);
      }
      else
      {
        decoded_message += decode_letter(current_letter);
        current_letter = "";
        delay(letter_space_time - pause_time);
      }
    }
    else
    {
      // ignore unknown characters
    }
    delay(pause_time);
  }
  if (current_letter != "")
  {
    decoded_message += decode_letter(current_letter);
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Received message:");
  display.setCursor(0, 16);
  display.print(decoded_message);
  display.display();
  delay(3000);
}

char decode_letter(String morse_code)
{
  if (morse_code == ".-")
  {
    return 'A';
  }
  else if (morse_code == "-...")
  {
    return 'B';
  }
  else if (morse_code == "-.-.")
  {
    return 'C';
  }
  else if (morse_code == "-..")
  {
    return 'D';
  }
  else if (morse_code == ".")
  {
    return 'E';
  }
  else if (morse_code == "..-.")
  {
    return 'F';
  }
  else if (morse_code == "--.")
  {
    return 'G';
  }
  else if (morse_code == "....")
  {
    return 'H';
  }
  else if (morse_code == "..")
  {
    return 'I';
  }
  else if (morse_code == ".---")
  {
    return 'J';
  }
  else if (morse_code == "-.-")
  {
    return 'K';
  }
  else if (morse_code == ".-..")
  {
    return 'L';
  }
  else if (morse_code == "--")
  {
    return 'M';
  }
  else if (morse_code == "-.")
  {
    return 'N';
  }
  else if (morse_code == "---")
  {
    return 'O';
  }
  else if (morse_code == ".--.")
  {
    return 'P';
  }
  else if (morse_code == "--.-")
  {
    return 'Q';
  }
  else if (morse_code == ".-.")
  {
    return 'R';
  }
  else if (morse_code == "...")
  {
    return 'S';
  }
  else if (morse_code == "-")
  {
    return 'T';
  }
  else if (morse_code == "..-")
  {
    return 'U';
  }
  else if (morse_code == "...-")
  {
    return 'V';
  }
  else if (morse_code == ".--")
  {
    return 'W';
  }
  else if (morse_code == "-..-")
  {
    return 'X';
  }
  else if (morse_code == "-.--")
  {
    return 'Y';
  }
  else if (morse_code == "--..")
  {
    return 'Z';
  }
  else
  {
    return '?'; // If the Morse code does not match any known letters, return '?'
  }
}
