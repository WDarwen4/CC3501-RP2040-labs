#define LED_PIN 14       // Define your LED data pin here
#define NUM_LEDS 12     // Define the number of LEDs

// Array to store the current state of each LED
uint32_t led_state[NUM_LEDS];

// Function to initialize LED states to off (black)
void initialize_led_states() {
    for (size_t i = 0; i < NUM_LEDS; i++) {
        led_state[i] = 0; // All LEDs off
    }
}

// Function to update the color of a specific LED
void set_led_color(uint8_t led_index, uint8_t red, uint8_t green, uint8_t blue) {
    if (led_index < NUM_LEDS) {
        led_state[led_index] = (red << 24) | (green << 16) | (blue << 8);
    }
}

// Function to send the LED data to the WS2812 strip
void update_leds() {
    for (size_t i = 0; i < NUM_LEDS; i++) {
        pio_sm_put_blocking(pio0, 0, led_state[i]);
    }
}