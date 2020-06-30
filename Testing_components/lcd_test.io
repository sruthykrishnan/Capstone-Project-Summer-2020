//Code for testing 16x2 LCD display with Arduino UNO

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);   //Setting the address location, number of columns and number of rows
void setup()
{
  lcd.init();                        //Initialize the LCD
  lcd.backlight();                   //Set the LCD background to light
}

void loop()
{
  lcd.setCursor(1,0);                //Set display pointer
  lcd.print("  SMART CAR");          //Output characters to the LCD1602
  lcd.setCursor(0,1);
  lcd.print("    PARKING");
  delay(1000);
}
