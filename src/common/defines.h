#ifndef DEFINES_H //if not defined then define, it ensures that its not being defined twice
#define DEFINES_H

#define UNUSED(x) (void)(x) //this define takes a variable and casts it to a void so this is basicallly done to ignore the compiler warnings for unused variables so this is at the run time in the body
#define SUPPRESS_UNUSED __attribute__((unused)) //this you use at the defination time to tell that varibable might be unused and no need to worry about it https://chatgpt.com/share/68deac72-e790-800e-bd79-72b7a8d6a078
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0])) //a function to calculate the array size
#define INTERRUPT_FUNCTION(vector) void __attribute__((interrupt(vector))) //for interrupt handling (not now)

#define MODULO_2(x) (x & 1) //to check if the number is odd or even
#define IS_ODD(x) MODULO_2(x) 
#define ABS(x) ((x) >= 0 ? (x) : -(x)) //absolute value function

#define CYCLES_1MHZ (1000000u)
#define CYCLES_16MHZ (16u * CYCLES_1MHZ)
#define CYCLES_PER_MS (CYCLES_16MHZ / 1000u)
#define ms_TO_CYCLES(ms) (CYCLES_PER_MS * ms)
#define BUSY_WAIT_ms(ms) (__delay_cycles(ms_TO_CYCLES(ms))) //custom delay function define

#define MCLK CYCLES_16MHZ //main and sub main clock
#define SMCLK MCLK

#define TIMER_INPUT_DIVIDER_3 (8u) // timre hardware register values
#define TIMER_MC_MASK (0x0030)

#endif // DEFINES_H
