

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
const char *msg;

// ALL Touch panels and wiring is DIFFERENT
// copy-paste results from TouchScreen_Calibr_native.ino
const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
const int TS_LEFT = 907, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

Adafruit_GFX_Button DISH1, DISH2,DISH3,DISH4,DISH5,DISH6,WAITER,BILL;

int pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup(void)
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
   // Serial.print("TFT ID = 0x");
   // Serial.println(ID, HEX);
    //Serial.println("Calibrate for your Touch Panel");
    if (ID == 0x5408) ID = 0x5408; // write-only shield
    tft.begin(ID);
    tft.setRotation(3);            //PORTRAIT
    tft.fillScreen(BLACK);
    DISH1.initButton(&tft,  60, 60, 100, 35, WHITE, CYAN, BLACK, "TEA", 2);
    DISH2.initButton(&tft, 230, 60, 100, 35, WHITE, CYAN, BLACK, "COFFEE", 2);
    DISH3.initButton(&tft,  60, 110, 100, 35, WHITE, CYAN, BLACK, "DOSA", 2);
    DISH4.initButton(&tft, 230, 110, 100, 35, WHITE, CYAN, BLACK, "IDLY", 2);
    DISH5.initButton(&tft,  60, 160, 100, 35, WHITE, CYAN, BLACK, "SAMBAR", 2);
    DISH6.initButton(&tft, 230, 160, 100, 35, WHITE, CYAN, BLACK, "PULAO", 2);
    WAITER.initButton(&tft, 70, 220, 120, 35, WHITE, RED, BLACK, "WAITER", 2);
    BILL.initButton(&tft, 230, 220, 120, 35, WHITE, RED, BLACK, "BILL", 2);
    
    DISH1.drawButton(false);
    DISH2.drawButton(false);
    DISH3.drawButton(false);
    DISH4.drawButton(false);
    DISH5.drawButton(false);
    DISH6.drawButton(false);
    WAITER.drawButton(false);
     BILL.drawButton(false);
      tft.setCursor (120, 10);
  tft.setTextSize (2);
  tft.setTextColor(RED);
  tft.println("MENU");
    
}

/* two buttons are quite simple
 */
void loop(void)
{
    bool down = Touch_getXY();
    DISH1.press(down && DISH1.contains(pixel_x, pixel_y));
    DISH2.press(down && DISH2.contains(pixel_x, pixel_y));
    DISH3.press(down && DISH3.contains(pixel_x, pixel_y));
    DISH4.press(down && DISH4.contains(pixel_x, pixel_y));
    DISH5.press(down && DISH5.contains(pixel_x, pixel_y));
    DISH6.press(down && DISH6.contains(pixel_x, pixel_y));
    WAITER.press(down && WAITER.contains(pixel_x, pixel_y));
    BILL.press(down && BILL.contains(pixel_x, pixel_y));
    
    if (DISH1.justReleased())
        DISH1.drawButton();
        
    if (DISH2.justReleased())
        DISH2.drawButton();
        
    if (DISH1.justPressed()) {
        DISH1.drawButton(true);
      // Serial.println("Dish 1");
         msg = "1";
         transmit();
    }
    if (DISH2.justPressed()) {
        DISH2.drawButton(true);
       // Serial.println("Dish 2");
         msg = "2";
         transmit();
       
    }
     if (DISH3.justReleased())
        DISH3.drawButton();
        
    if (DISH4.justReleased())
        DISH4.drawButton();
        
    if (DISH3.justPressed()) {
        DISH3.drawButton(true);
      // Serial.println("Dish 3");
        msg = "3";
         transmit();
    }
    if (DISH4.justPressed()) {
        DISH4.drawButton(true);
      //  Serial.println("Dish 4");
         msg = "4";
         transmit();
       
    }
     if (DISH5.justReleased())
        DISH5.drawButton();
        
    if (DISH6.justReleased())
        DISH6.drawButton();
        
    if (DISH5.justPressed()) {
        DISH5.drawButton(true);
      // Serial.println("Dish 5");
        msg = "5";
         transmit();
    }
    if (DISH6.justPressed()) {
        DISH6.drawButton(true);
       // Serial.println("DISH 6");
         msg = "6";
         transmit();
       
    }
     if (WAITER.justReleased())
        WAITER.drawButton();
        
    if (WAITER.justPressed()) {
        WAITER.drawButton(true);
       // Serial.println("WAITER");
         msg = "7";
         transmit();
       
    }
    if (BILL.justReleased())
        BILL.drawButton();
        
    if (BILL.justPressed()) {
        BILL.drawButton(true);
       // Serial.println("WAITER");
         msg = "8";
         transmit();
       
    }
}


void transmit()
{ 
 Serial.println(msg);
  delay(100);
  }
