//////////////////////////////////////////////////////////////////////
//
//    filename: rgb_ledstrip_colorfade.ino
// description: Simple sketch to automatically fade through all colors
//      author: hyper3xpl0iter
//       email: devel@introsec.ca
//         GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD
//        date: 07/18/2016
//
//////////////////////////////////////////////////////////////////////

// define pins (must be PWM pins)

// Channel 01
#define redPinOne 6
#define greenPinOne 5
#define bluePinOne 3

// Channel 02
#define redPinTwo 11
#define greenPinTwo 10
#define bluePinTwo 9

// make this higher to slow down
#define FADESPEED 20

void setup() {
	pinMode(redPinOne, OUTPUT);
    pinMode(greenPinOne, OUTPUT);
    pinMode(bluePinOne, OUTPUT);
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
    Serial.println("//    filename: rgb_ledstrip_colorfade.ino");
    Serial.println("// description: Simple sketch to automatically fade through all colors");
    Serial.println("//      author: hyper3xpl0iter");
    Serial.println("//       email: devel@introsec.ca");
    Serial.println("//         GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD");
    Serial.println("//        date: 07/18/2016");
    Serial.println("//");
    Serial.println("//////////////////////////////////////////////////////////////////////");
}


void loop() {
	int r, g, b;

	// fade from blue to violet
	Serial.println("Fading: Blue to Violet");
	for (r = 0; r < 256; r++) {
		analogWrite(redPinOne, r);
        analogWrite(redPinTwo, r);
        delay(FADESPEED);
	}

	// fade from violet to red
	Serial.println("Fading: Violet to Red");
	for (b = 255; b > 0; b--) {
		analogWrite(bluePinOne, b);
        analogWrite(bluePinTwo, b);
        delay(FADESPEED);
	}

	// fade from red to yellow
	Serial.println("Fading: Red to Yellow");
	for (g = 0; g < 256; g++) {
        analogWrite(greenPinOne, g);
        analogWrite(greenPinTwo, g);
        delay(FADESPEED);
	}

	// fade from yellow to green
	Serial.println("Fading: Yellow to Green");
	for (r = 255; r > 0; r--) {
        analogWrite(redPinOne, r);
        analogWrite(redPinTwo, r);
        delay(FADESPEED);
	}

	// fade from green to teal
	Serial.println("Fading: Green to Teal");
	for (b = 0; b < 256; b++) {
		analogWrite(bluePinOne, b);
		analogWrite(bluePinTwo, b);
		delay(FADESPEED);
	}

	// fade from teal to blue
	Serial.println("Fading: Teal to Blue");
	for (g = 255; g > 0; g--) {
		analogWrite(greenPinOne, g);
		analogWrite(greenPinTwo, g);
		delay(FADESPEED);
	}
}

