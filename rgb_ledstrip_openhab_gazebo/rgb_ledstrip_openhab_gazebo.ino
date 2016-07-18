/////////////////////////////////////////////////////////////////////
//
//	   Filename: ledstrip_openhab_gazebo.ino
//	Description: Control RGB LED strips via OpenHAB w/ NRF24 chips
//	     Author: hyper3xpl0iter
//        Email: devel@introsec.ca
//          GPG: B9C0 3976 3CB4 794E D66C 8F75 8AA0 8470 3533 2EDD
//         Date: 07/16/2016
//
/////////////////////////////////////////////////////////////////////

// Import needed libraries
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

// pin definitions.  must be PWM-capable pins!
// channel 01 pin definitions
//#define REDPINONE 6
//#define GREENPINONE 5
//#define BLUEPINONE 3
byte	REDPINONE = 6
byte	GREENPINONE = 5
byte	BLUEPINONE = 3

// channel 02 pin definitions
//#define REDPINTWO 11
//#define GREENPINTWO 10
//#define BLUEPINTWO 9
byte REDPINTWO = 11
byte GREENPINTWO = 10
byte BLUEPINTWO = 9

// fadespeed definitoin (make this higher to slow down)
#define FADESPEED 20


// configure NRF24 connection and LED pins
void setup() {
	// Set up the Serial Monitor
    Serial.begin(9600);

    // Initialize all radio related modules
    SPI.begin();
    radio.begin();
    delay(5);
    network.begin(90, this_node);

    // Configure LED pin
    pinMode(REDPINONE, OUTPUT);
    pinMode(GREENPINONE, OUTPUT);
    pinMode(BLUEPINONE, OUTPUT);
    pinMode(REDPINTWO, OUTPUT);
    pinMode(GREENPINTWO, OUTPUT);
    pinMode(BLUEPINTWO, OUTPUT);
}


 // make loop to cycle through colors and for statments defining colors to fade too
void loop() {

	// Update network data
	network.update();

	while (network.available()) {
		RF24NetworkHeader header;
		message_action message;
		network.peek(header);
		if (header.type == '2') {
			network.read(header, &message, sizeof(message));
			Serial.print("Data received from node ");
			Serial.println(header.from_node);

			// Check value and turn the LED on or off
			Serial.print("Value: ");
			Serial.println(message.state);
			if (message.state) {
			digitalWrite(ledPin, HIGH);
			}

			else {
				digitalWrite(ledPin, LOW);
			}
		}

		else {
			// This is not a type we recognize
			network.read(header, &message, sizeof(message));
			Serial.print("Unknown message received from node ");
			Serial.println(header.from_node);
		}
	}

	// Wait a bit before we start over again
	delay(interval);

// TODO
// MAY NEED TO BE REMOVED
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
