#pragma once 

#include <vector>

// Types defined just so that we can replicate the real API

// A "program" in the mock is a function pointer that is called with the data being delivered to the PIO.
typedef void (*pio_program_t)(uint32_t data);

// Mock of the PIO structure defined by the Pico SDK
struct PIO {
    // Record the list of programs that have been registered
    std::vector<pio_program_t> programs;
};
extern PIO pio0;

// Functions defined to replicate the real API
unsigned int pio_add_program(PIO &pio, const pio_program_t* program);
void pio_sm_put_blocking(PIO &pio, unsigned int sm, uint32_t data);
