#include <lpc214x.h>

// LED pin definition
#define LED_PIN (1 << 0) // P0.0

// Class to encapsulate LED functionality
class LED {
public:
    // Constructor: Initialize GPIO pin for LED
    LED() {
        IODIR0 |= LED_PIN;   // Set P0.0 as output
        IOSET0 = LED_PIN;    // Turn LED off initially
    }

    // Function to turn the LED on
    void on() {
        IOCLR0 = LED_PIN;    // Clear P0.0 (turn LED on)
    }

    // Function to turn the LED off
    void off() {
        IOSET0 = LED_PIN;    // Set P0.0 (turn LED off)
    }

    // Function to toggle the LED
    void toggle() {
        if (IOPIN0 & LED_PIN) {
            on();            // If LED is off, turn it on
        } else {
            off();           // If LED is on, turn it off
        }
    }
};

int main() {
    LED led;                 // Create an LED object

    while (1) {
        led.toggle();        // Toggle the LED state
        for (volatile int i = 0; i < 1000000; i++); // Simple delay loop
    }

    return 0;
}