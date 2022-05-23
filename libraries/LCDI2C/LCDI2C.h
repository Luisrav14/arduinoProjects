#ifndef LCDI2Ct_h

#define LCDI2C_h

#define CMDDELAY = 50;        // Delay to wait after sending commands;


#include <inttypes.h>



class LCDI2C {

public:

  LCDI2C(int num_lines,int i2c_address);

  void commandWrite(int value);

  void init();

  void print(int value);

  void println(char value[]);

  void clear();
  
  void home();
  
  void on();
  
  void off();
  
  void cursor_on();
  
  void cursor_off();
  
  void blink_on();
  
  void blink_off();
  
  void left();
  
  void right();
  
  int keypad();
  
  void position(int line_num, int x);



};



#endif

