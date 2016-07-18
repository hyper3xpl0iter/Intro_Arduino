//////////////////////////////////////////////////////////////////////
//
//    filename: rgb_ledstrip_testing.ino
// description: Simple sketch to manually update color for testing
//      author: hyper3xpl0iter
//       email: devel@introsec.ca
//         GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD
//        date: 07/18/2016
//
//////////////////////////////////////////////////////////////////////

//pin definitions.  must be PWM-capable pins!
const int redPinOne = 9;
const int greenPinOne = 10;
const int bluePinOne = 11;

const int redPinTwo = 6;
const int greenPinTwo = 5;
const int bluePinTwo = 3;

//maximum duty cycle to be used on each led for color balancing.
//if "white" (R=255, G=255, B=255) doesn't look white, reduce the red, green, or blue max value.
const int max_red = 255;	//255
const int max_green = 255;	//90
const int max_blue = 255;	//100

//array to store led brightness values
byte colors[3] = {0, 0, 0};

//10 in decimal, ASCII newline character
byte lineEnding = 0x0A;

void setup(){
	//set both channels LED pins as outputs

	// Channel 01
	pinMode(redPinOne, OUTPUT);
	pinMode(greenPinOne, OUTPUT);
	pinMode(bluePinOne, OUTPUT);

	// Channel 02
	pinMode(redPinTwo, OUTPUT);
	pinMode(greenPinTwo, OUTPUT);
	pinMode(bluePinTwo, OUTPUT);

	// initialize serial and wait for port to open:
	Serial.begin(9600);

	// wait for serial port to connect.
	while (!Serial) {
		;
	}
	Serial.println("Serial communications are initiated");

	// Print sketch information
	Serial.println("//////////////////////////////////////////////////////////////////////");
	Serial.println("//");
	Serial.println("//    filename: rgb_ledstrip_testing.ino");
	Serial.println("// description: Simple sketch to manually update color for testing");
	Serial.println("//      author: hyper3xpl0iter");
	Serial.println("//       email: devel@introsec.ca");
	Serial.println("//         GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD");
	Serial.println("//        date: 07/18/2016");
	Serial.println("//");
	Serial.println("//////////////////////////////////////////////////////////////////////");

}

void loop(){

	// set pin values based on data read from the serial port
	//
	// map() is used so the R, G, and B brightnesses are balanced.
	//
	// replace "255" with the desired about of color for that LED

	// Channel 01 color map
	analogWrite(redPinOne, map(colors[0], 0, 255, 0, max_red));
	analogWrite(greenPinOne, map(colors[1], 0, 255, 0, max_green));
	analogWrite(bluePinOne, map(colors[2], 0, 255, 0, max_blue));
	Serial.println("Channel 01 is powered on");

	// Channel 02 color map
	analogWrite(redPinTwo, map(colors[0], 0, 255, 0, max_red));
	analogWrite(greenPinTwo, map(colors[1], 0, 255, 0, max_green));
	analogWrite(bluePinTwo, map(colors[2], 0, 255, 0, max_blue));
	Serial.println("Channel 02 is powered on");
}
