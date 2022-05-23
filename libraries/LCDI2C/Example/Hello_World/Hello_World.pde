// example use of LCDI2C library with the web4robot.com i2C lcd display

#include <Wire.h>
#include <LCDI2C.h>
#include <stdio.h>


LCDI2C lcd = LCDI2C(2,0x4C);             // Number of lines and i2c address of the display


void setup() { 


  lcd.init();                          // Init the display, clears the display
 
  lcd.println("Hello World!");       // Classic Hello World!
 
  
}


void loop()
{
  
 char s[20]; 
 
  lcd.position(1,0);                      // Place the cursor on the 2nd line
  
  sprintf(s,"keypad = %3d",lcd.keypad());  // Check to see if a key has been pressed
  
  lcd.println(s);                          // Print the value we got back from the keypad

  delay(1);
  
  
}
