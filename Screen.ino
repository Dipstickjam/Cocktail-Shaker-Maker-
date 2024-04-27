// Images
#include "introPic.h"
#include "cocktailPic.h"
#include "sleepDrinksPic.h"

// Screen Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay(){
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
  display.setRotation(0);
}

void showIntro(){
  //display.drawBitmap(0, 0, introPic, 128, 64, SH110X_WHITE);
  display.drawBitmap(0, 0, cocktailPic, 128, 64, SH110X_WHITE);

  display.setCursor(10,1);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.print("Cocktail");
   display.setCursor(10,20);
  display.print("Shaker");
    display.setCursor(10,40);
    display.print("Maker");


  display.display();
  //delay(500);

}

void showDrinks(){
  static int scrollTimer = millis();
  clearDisplay();
  //display.drawBitmap(0, 0, sunrisePic, 128, 64, SH110X_WHITE);
  display.setCursor(10, 10+yOffset);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
    display.println(drinks);
  display.setTextSize(1);
  display.println("");

  if(millis() - scrollTimer > 500) {
    yOffset = yOffset - 1;
    scrollTimer = millis();
  } 

  //display.setCursor(10,25+yOffset);
  //display.setTextColor(SH110X_WHITE);
  //inst = "string";
  //Serial.print(inst);
  display.println((const char*)doc["drinks"][0]["strInstructions"]);
  display.println("");
  

   //display.setCursor(10,50+yOffset);
   for(int i=1;i<=15;i++){
    //display.setCursor(10, 50+i*10+yOffset);
    display.print(ingredients[i]);
    display.print(" - ");
    display.println(quantity[i]);
}
  display.display();
}

// void showInstructions(){
//   display.drawBitmap(0, 0, sunsetPic, 128, 64, SH110X_WHITE);
//   display.setCursor(10, 10);
//   display.setTextWrap(true);
//   display.setTextSize(1);
//   display.setTextColor(SH110X_WHITE, SH110X_BLACK);
//   display.print(instructions);
//   display.display();
//}

// int sunX = 32;  int sunSpeedY = 1;
// int sunY = 32;  int sunSpeedX = 1;

void showSleep(){
  // sunX += sunSpeedX;
  // sunY += sunSpeedY;
  // display.drawCircle(sunX, sunY, 5, SH110X_WHITE);
  // if(sunX < 0 || sunX > 128){sunSpeedX = -sunSpeedX;}
  // if(sunY < 0 || sunY > 64){sunSpeedY = -sunSpeedY;}
  display.drawBitmap(0, 0, sleepdrinks, 128, 64, SH110X_WHITE);
  display.display();
}

void clearDisplay(){display.clearDisplay();}