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
  static uint32_t loadingProgress = 0;

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


void displayError()
{
  static uint32_t animationFrame = 0;

  if (animationFrame % 4 < 2)
  {

   display.setTextSize(2);
  display.setCursor(10, 28);

  display.setTextColor(WHITE);
  display.println("ERROR !!!");
  }
  animationFrame++;
}

void displayEyes()
{
  static uint32_t animationFrame = 0;
  
  const int LeftEyeSize[] = {10, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 0, 10, 0, 10, 0, 10, };
  const int RightEyeSize[] = {10, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 0, 10, 0, 10, 0, }; // prettier-ignore
  const int LeftEyeOffsetX[] = {0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0};
  const int RightEyeOffsetX[] = {0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0};
  const int LeftEyeOffsetY[] = {0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,  -1, -1, -2, -2, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -2, -2, -1, -1, 0 };
  const int RightEyeOffsetY[] = {0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,  -1, -1, -2, -2, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -2, -2, -1, -1, 0 };


  const int LeftEyeSizeLength = sizeof(LeftEyeSize) / sizeof(int);
  const int RightEyeSizeLength = sizeof(RightEyeSize) / sizeof(int);
  const int LeftEyeOffsetXLength = sizeof(LeftEyeOffsetX) / sizeof(int);
  const int RightEyeOffsetXLength = sizeof(RightEyeOffsetX) / sizeof(int);
  const int LeftEyeOffsetYLength = sizeof(LeftEyeOffsetY) / sizeof(int);
  const int RightEyeOffsetYLength = sizeof(RightEyeOffsetY) / sizeof(int);

  display.fillCircle(32, 32, 17, SSD1306_WHITE);
  display.fillCircle(32 + LeftEyeOffsetX[animationFrame % LeftEyeOffsetXLength], 32 + LeftEyeOffsetY[animationFrame % LeftEyeOffsetYLength], LeftEyeSize[animationFrame % LeftEyeSizeLength], SSD1306_BLACK);

  display.fillCircle(96, 32, 17, SSD1306_WHITE);
  display.fillCircle(96 + RightEyeOffsetX[animationFrame % RightEyeOffsetXLength], 32+ RightEyeOffsetY[animationFrame % RightEyeOffsetYLength], RightEyeSize[animationFrame % RightEyeSizeLength], SSD1306_BLACK);
  animationFrame++;
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



  for (int i = 0; i < 100; i++)
  {

    display.clearDisplay();
    if (i % 2 == 1)
      displayLoadingBar(false);
    else
      displayLoadingBar(true);
    if (i % 21 < 3)
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
  static uint32_t i = 0;

    display.clearDisplay();


    if (i % 200 < 40)
      displayError();
    else
      displayEyes();
    if (i % 72 < 3)
      displayGlitch();
    display.display();
    
    display.display();

    delay(100);

i++;
  // put your main code here, to run repeatedly:
}
