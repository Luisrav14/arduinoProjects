/*

LCDI2C v0.1 28/Feb/2009 Dale Wentz http://wentztech.com/Radio


What is this?

An arduino library for use with the web4robot.com i2C LCD Display in I2C more

Uses I2c Wires interface

Uses Analog pin 4 - SDA
Uses Analog pin 5 - SCL

Sources:

- Based on the code for the arduino-4bitlcd libary from http://code.google.com/p/arduino-4bitlcd/

Misc:

- I have no intrest in web4robot.com or IMS. I purchased one of their displays becouse it used I2C

Usage:

see the examples folder of this library distribution.


*/


  #include <Wire.h>

  #include <stdio.h>  //not needed yet

  #include <string.h> //needed for strlen()

  #include <inttypes.h>

  #include "WConstants.h"  //all things wiring / arduino
  
  #include "LCDI2C.h"
  



//--------------------------------------------------------

// (don't change here - specify on calling constructor)

//how many lines has the LCD? 

int g_num_lines = 2;

// Defalt address of the display

int g_i2caddress = 0x4C;


//stuff the library user might call---------------------------------

//constructor.  num_lines must be 1, 2, 3, or 4 currently.

LCDI2C::LCDI2C (int num_lines,int i2c_address) {

  g_num_lines = num_lines;
  g_i2caddress = i2c_address;

  if (g_num_lines < 1 || g_num_lines > 4)

  {

    g_num_lines = 2;

  }

}


void LCDI2C::commandWrite(int value) {

  Wire.beginTransmission(g_i2caddress);
  Wire.send(0xFE);
  Wire.send(value);
  Wire.endTransmission();
  delay(50);
}


//print the given character at the current cursor position. overwrites, doesn't insert.

void LCDI2C::print(int value) {

  Wire.beginTransmission(g_i2caddress);
  Wire.send(value);
  Wire.endTransmission();
  delay(50);

}


//print the given string to the LCD at the current cursor position.  overwrites, doesn't insert.


void LCDI2C::println(char msg[]) {

   uint8_t i;  //fancy int.  avoids compiler warning when comparing i with strlen()'s uint8_t
    
    //Serial.println(g_i2caddress);
    
    Wire.beginTransmission(g_i2caddress);
    
      for (i=0;i < strlen(msg);i++){
          Wire.send(msg[i]);
      }
    Wire.endTransmission();
    delay(50);
  

}



//send the clear screen command to the LCD

void LCDI2C::clear(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x14);
      Wire.endTransmission();
      delay(50);  


}

//send the Home Cursor command to the LCD      ********** Not Working ***************

void LCDI2C::home(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x0D);
      Wire.endTransmission();
      delay(50); 
}

//Turn the LCD ON

void LCDI2C::on(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x0A);
      Wire.endTransmission();
      delay(50);  
}

// Turn the LCD OFF
void LCDI2C::off(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x0B);
      Wire.endTransmission();
      delay(50);
        
}

//Turn the Underline Cursor ON

void LCDI2C::cursor_on(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x0E);
      Wire.endTransmission();
      delay(50);
        
}

//Turn the Underline  Cursor OFF

void LCDI2C::cursor_off(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x0F);
      Wire.endTransmission();
      delay(50);
      
}

//Turn the Underline Cursor ON

void LCDI2C::blink_on(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x12);
      Wire.endTransmission();
      delay(50);
        
}

//Turn the Underline  Cursor OFF

void LCDI2C::blink_off(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x13);
      Wire.endTransmission();
      delay(50);
      
}

//Move the cursor left 1 space

void LCDI2C::left(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x10);
      Wire.endTransmission();
      delay(50);
        
}

//Move the cursor right 1 space

void LCDI2C::right(){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x11);
      Wire.endTransmission();
      delay(50);
      
}


// initiatize lcd after a short pause

//while there are hard-coded details here of lines, cursor and blink settings, you can override these original settings after calling .init()

void LCDI2C::init () {

      Wire.begin();
      on();
      clear();
      blink_off();
      cursor_off(); 
      position(0,0);
      
    
     
}




void LCDI2C::position(int line_num, int x){

      Wire.beginTransmission(g_i2caddress);
      Wire.send(0xFE);
      Wire.send(0x0C);
      Wire.send(line_num);
      Wire.send(x);
      Wire.endTransmission();
      delay(100);

}



int LCDI2C::keypad (){

  int data = 0;

  //  Send Keypad read command
  Wire.beginTransmission(g_i2caddress);
  Wire.send(0xFE);
  Wire.send(0x1B);
  Wire.endTransmission();
  delay(50);
  
  //  Connect to device and request two bytes
  Wire.beginTransmission(g_i2caddress);
  Wire.requestFrom(g_i2caddress, 1);

  if (Wire.available()) {
    data = Wire.receive();
  }


return data;
}
