#include "drivers/led.h" //this is the LED specific defines
#include "drivers/io.h" //all gpio related defines
#include "common/defines.h" //this include commanly used defines
#include "common/assert_handler.h" //for error checking and debugging
#include <stdbool.h>

static const struct io_config led_config = {
    .select = IO_SELECT_GPIO,     //normal gpio, no uart, usart           //basically a struct, the definition of io_config whould be somewhere is the io.h. and they are assiged to some value. the initialization way is a specific called designated initializer.
    .resistor = IO_RESISTOR_DISABLED, //no pullup or pulldown resistor needed    
    .dir = IO_DIR_OUTPUT, //set to output gpio
    .out = IO_OUT_LOW, //start with off mode
};

static bool initialized = false; 
void led_init(void)
{
    ASSERT(!initialized); //safety check of not double initialization
    struct io_config current_config;
    io_get_current_config(IO_TEST_LED, &current_config); //storing the current led config into current_config
    ASSERT(io_config_compare(&led_config, &current_config)); //comparing the config of the current led setup with what we just definied and testing it
    initialized = true;
}

void led_set(led_e led, led_state_e state)
{
    ASSERT(initialized); //this makes sure then after the init is done this step is executed
    const io_out_e out = (state == LED_STATE_ON) ? IO_OUT_HIGH : IO_OUT_LOW;
    switch (led) {
    case LED_TEST:
        io_set_out(IO_TEST_LED, out); //this is where it actually turns on or off
        break;
    }
}
