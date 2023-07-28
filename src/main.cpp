#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

// SDA => D2
// SCK => D1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayGlitch()
{
  int rand_line_number = 1 + random() % 6;
  for (int i = 0; i < rand_line_number; i++)
  {
    int rand_nu = random() % 64;
    display.drawLine(0, rand_nu, 128, rand_nu, SSD1306_WHITE);
  }
}

void displayLoadingBar(boolean updateProgress)
{
  static int loadingProgress = 0;

  display.fillRect(65, 19, 7, 7, SSD1306_WHITE);
  display.fillRect(65, 10, 7, 7, SSD1306_WHITE);

  display.fillRect(74, 19, 7, 7, SSD1306_WHITE);
  display.fillRect(74, 10, 7, 7, SSD1306_WHITE);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(37, 28);
  display.println("Windows XP");
  display.drawRect(40, 40, 47, 7, SSD1306_WHITE);

  display.fillRect(42 + (loadingProgress % 11 * 4), 42, 3, 3, SSD1306_WHITE);
  display.fillRect(42 + ((loadingProgress + 1) % 11 * 4), 42, 3, 3, SSD1306_WHITE);
  display.fillRect(42 + ((loadingProgress + 2) % 11 * 4), 42, 3, 3, SSD1306_WHITE);
  if (updateProgress)
    loadingProgress++;
}

void displayEyes()
{
  display.fillCircle(32, 32, 6, SSD1306_WHITE);


}


void setup()
{

  Serial.begin(115200);
  // Wire.begin(1, 15);
  //  second_wire.begin(9,10);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  display.clearDisplay();

  display.println("Impossible to connect WiFi network, go to deep sleep");
  displayEyes();
  display.display();
  delay(3000);

  for (int i = 0; i < 100; i++)
  {

    display.clearDisplay();
    if (i % 2 == 1)
      displayLoadingBar(false);
    else
      displayLoadingBar(true);
    if (i % 13 < 3)
      displayGlitch();
    display.display();
    delay(100);
  }

  // delay(1000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
