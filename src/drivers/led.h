#ifndef LED_H

// Simple driver for controlling GPIOs with LEDs connected to them.

typedef enum
{
    LED_TEST, // this is an enum defined to to list all the led in the system, by default     LED_TEST = 0, what is an enum (https://chatgpt.com/share/68de93a5-0550-800e-b9af-87e9d559ee4f)
} led_e;

typedef enum
{
    LED_STATE_OFF, // so similarly you defined another enum for the state of leds possible which would be 0 and 1 so off or on.
    LED_STATE_ON
} led_state_e;

void led_init(void); // sets up the hardware for the initialization of LED
void led_set(led_e led, led_state_e state); //tells which led to turn on and what state off or on, this ensures that the values would be from the enums

#endif // LED_H
