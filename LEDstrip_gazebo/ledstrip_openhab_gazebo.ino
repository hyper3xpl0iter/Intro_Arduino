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

//pin definitions.  must be PWM-capable pins!
//Channel 01 pin settings (
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

const int BredPin = 11;
const int BgreenPin = 10;
const int BbluePin = 9;


//pin definitions for amp02

//maximum duty cycle to be used on each led for color balancing.  
//if "white" (R=255, G=255, B=255) doesn't look white, reduce the red, green, or blue max value.
const int max_red = 255;
const int max_green = 90;
const int max_blue = 100;

byte colors[3] = {0, 0, 0}; //array to store led brightness values
byte lineEnding = 0x0A; //10 in decimal, ASCII newline character

void setup(){
  //set all three of our led pins to output
  // Amp01 pin mode
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Amp02 pin mode
  pinMode(BredPin, OUTPUT);
  pinMode(BgreenPin, OUTPUT);
  pinMode(BbluePin, OUTPUT);
  
  //start the Serial connection
  Serial.begin(115200);
}

void loop(){
  //check that at least 3 bytes are available on the Serial port
  if (Serial.available() > 2){
     //store data up until lineEnding (0x0A) in the bytesRead array
     int bytesRead = Serial.readBytesUntil(lineEnding, (char*)colors, 3);
  }  
  //set the three PWM pins according to the data read from the Serial port
  //we also scale the values with map() so that the R, G, and B brightnesses are balanced.
  analogWrite(redPin, map(colors[0], 0, 255, 0, max_red));
  analogWrite(greenPin, map(colors[1], 0, 0, 0, max_green));
  analogWrite(bluePin, map(colors[2], 0, 0, 0, max_blue));

  // Amp02 write config
  analogWrite(BredPin, map(colors[0], 0, 255, 0, max_red));
  analogWrite(BgreenPin, map(colors[1], 0, 0, 0, max_green));
  analogWrite(BbluePin, map(colors[2], 0, 0, 0, max_blue));
}