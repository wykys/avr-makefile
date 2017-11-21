#include "settings.h"
#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define N 4

extern void asm_copy(uint8_t*, uint8_t*, uint8_t);
extern uint8_t asm_rand(uint8_t);

uint8_t a[N] = {0};
uint8_t b[N] = {0};
char buffer[9];

void rand_test(uint8_t tmp)
{
  uart_puts("\n\r");
  uart_puts("RAND ");
  uart_puts("Input values = ");
  itoa(tmp, buffer, 10);
  uart_puts(buffer);
  uart_puts(" Output values = ");
  tmp = asm_rand(tmp);
  itoa(tmp, buffer, 10);
  uart_puts(buffer);
}

int main(void)
{
    int i;
    
    // Setup all peripheries
    uart_init();

    // Set input vector
    for (i=0; i<N; i++)
        a[i] = 2*i + 1;

    // Call assembly function
    asm_copy(a, b, N);

    // Enable interrupts. Needed for uart_puts(), uart_putc()
    sei();

    // Transmit data to UART
    uart_puts("\n\r");
    uart_puts("Input values = \n\r");
    for (i=0; i<N; i++){
        itoa(a[i], buffer, 10);
        uart_puts(buffer);
        uart_putc(' ');
    }
    uart_puts("\n\r");
    uart_puts("Output values = \n\r");
    for (i=0; i<N; i++){
        itoa(b[i], buffer, 10);
        uart_puts(buffer);
        uart_putc(' ');
    }


    for (i=0; i<N; i++){
        rand_test(a[i]);
    }

    while (1);

    return 0;
}
