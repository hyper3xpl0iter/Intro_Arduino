/////////////////////////////////////////////////////////////////////
//
//	   Filename: ledstrip_openhab_gazebo.ino
//	Description: Control RGB LED stips via OpenHAB w/ NRF24 chips 
//	     Author: hyper3xpl0iter
//        Email: devel@introsec.ca
//          GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD
//         Date: 07/16/2016
//
/////////////////////////////////////////////////////////////////////

// pin definitions.  must be PWM-capable pins!
// channel 01 pin definitions
    #define REDPINONE 6
    #define GREENPINONE 5
    #define BLUEPINONE 3
    


// channel 02 pin definitions
	#define REDPINTWO 11
    #define GREENPINTWO 10
    #define BLUEPINTWO 9
     
// fadespeed definitoin (make this higher to slow down)   
	#define FADESPEED 20

// define a mode for the pins
    void setup() {
      pinMode(REDPINONE, OUTPUT);
      pinMode(GREENPINONE, OUTPUT);
      pinMode(BLUEPINONE, OUTPUT);
      pinMode(REDPINTWO, OUTPUT);
      pinMode(GREENPINTWO, OUTPUT);
      pinMode(BLUEPINTWO, OUTPUT);
    }
     

 // make loop to cycle through colors and for statments defining colors to fade too
    void loop() {
      int r, g, b;
     
      // fade from blue to violet
      for (r = 0; r < 256; r++) { 
        analogWrite(REDPINONE, r);
        analogWrite(REDPINTWO, r);
        delay(FADESPEED);
      } 
      // fade from violet to red
      for (b = 255; b > 0; b--) { 
        analogWrite(BLUEPINONE, b);
        analogWrite(BLUEPINTWO, b);
        delay(FADESPEED);
      } 
      // fade from red to yellow
      for (g = 0; g < 256; g++) { 
        analogWrite(GREENPINONE, g);
        analogWrite(GREENPINTWO, g);
        delay(FADESPEED);
      } 
      // fade from yellow to green
      for (r = 255; r > 0; r--) { 
        analogWrite(REDPINONE, r);
        analogWrite(REDPINTWO, r);
        delay(FADESPEED);
      } 
      // fade from green to teal
      for (b = 0; b < 256; b++) { 
        analogWrite(BLUEPINONE, b);
        analogWrite(BLUEPINTWO, b);
        delay(FADESPEED);
      } 
      // fade from teal to blue
      for (g = 255; g > 0; g--) { 
        analogWrite(GREENPINONE, g);
        analogWrite(GREENPINTWO, g);
        delay(FADESPEED);
      } 
    }
