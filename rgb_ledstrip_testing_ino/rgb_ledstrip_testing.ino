//////////////////////////////////////////////////////////////////////
//
//    filename: rgb_ledstrip_testing.ino
// description: Simple sketch to manual update color for testing
//      author: hyper3xpl0iter
//       email: devel@th3c1inic.org
//         GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD
//        date: 07/18/2016
//
//////////////////////////////////////////////////////////////////////

//pin definitions.  must be PWM-capable pins!
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int redPinTwo = 6
const int greenPinTwo = 5
const int bluePinTwo = 3

//maximum duty cycle to be used on each led for color balancing.
//if "white" (R=255, G=255, B=255) doesn't look white, reduce the red, green, or blue max value.

// TODO
//const int max_red = 255;
//const int max_green = 90;
//const int max_blue = 100;

const int max_red = 255;
const int max_green = 255;
const int max_blue = 255;

//array to store led brightness values
byte colors[3] = {0, 0, 0};

//10 in decimal, ASCII newline character
byte lineEnding = 0x0A;

void setup(){
  //set both channels led pins to output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(redPinTwo, OUTPUT);
  pinMode(greenPinTwo, OUTPUT);
  pinMode(bluePinTwo, OUTPUT);

  // initialize serial and wait for port to open:
  Serial.begin(9600);

  // wait for serial port to connect.
  while (!serial) {
	  ;
  }
}

void loop(){

  // set the three PWM pins according to the data read from the Serial port
  // map() so that the R, G, and B brightnesses are balanced.

	// replace "255" with the desired about of color for that LED
	// Channel 01 color map
	analogWrite(redPin, map(colors[0], 0, 255, 0, max_red));
	analogWrite(greenPin, map(colors[1], 0, 255, 0, max_green));
	analogWrite(bluePin, map(colors[2], 0, 255, 0, max_blue));

	// Channel 02 color map
	analogWrite(redPinTwo, map(colors[0], 0, 255, 0, max_red));
	analogWrite(greenPinTwo, map(colors[1], 0, 255, 0, max_green));
	analogWrite(bluePinTwo, map(colors[2], 0, 255, 0, max_blue));
