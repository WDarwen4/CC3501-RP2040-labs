#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "drivers/leds.h"
#include "ws2812.pio.h"

int main() {
    stdio_init_all();

    // Initialize PIO0 to control the LED chain
    uint pio_program_offset = pio_add_program(pio0, &ws2812_program);
    ws2812_program_init(pio0, 0, pio_program_offset, LED_PIN, 800000, false);

    // Initialize LED states
    initialize_led_states();

    // Example of changing a single LED
    set_led_color(0, 255, 0, 0); // Set LED 0 
    set_led_color(1, 0, 255, 0); // Set LED 1 
    set_led_color(2, 0, 0, 255); // Set LED 2 
    set_led_color(3, 255, 0, 0); // Set LED 3
    set_led_color(4, 0, 255, 0); // Set LED 4 
    set_led_color(5, 0, 0, 255); // Set LED 5 
    set_led_color(6, 255, 0, 0); // Set LED 6 
    set_led_color(7, 0, 255, 0); // Set LED 7 
    set_led_color(8, 0, 0, 255); // Set LED 8 
    set_led_color(9, 255, 0, 0); // Set LED 9
    set_led_color(10, 0, 255, 0); // Set LED 10 
    set_led_color(11, 0, 0, 255); // Set LED 11

    // Update all LEDs
    update_leds();

    // Main loop
    for (;;) {
        
    }

    return 0;
}
