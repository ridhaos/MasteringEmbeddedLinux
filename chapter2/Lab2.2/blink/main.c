#include <stdint.h>

// Raspberry Pi 4 UART (PL011) and GPIO registers
#define UART0_BASE  0xFE201000  // UART0 base address (RPi4)
#define GPIO_BASE   0xFE200000  // GPIO base address (RPi4)

// UART registers
volatile uint32_t* UART0_DR     = (uint32_t*)(UART0_BASE + 0x00);  // Data register
volatile uint32_t* UART0_FR     = (uint32_t*)(UART0_BASE + 0x18);  // Flag register
volatile uint32_t* UART0_IBRD   = (uint32_t*)(UART0_BASE + 0x24);  // Integer baud rate divisor
volatile uint32_t* UART0_FBRD   = (uint32_t*)(UART0_BASE + 0x28);  // Fractional baud rate divisor
volatile uint32_t* UART0_LCRH   = (uint32_t*)(UART0_BASE + 0x2C);  // Line control register
volatile uint32_t* UART0_CR     = (uint32_t*)(UART0_BASE + 0x30);  // Control register

// GPIO registers
volatile uint32_t* GPFSEL1      = (uint32_t*)(GPIO_BASE + 0x04);   // GPIO function select (for GPIO 16)
volatile uint32_t* GPFSEL2      = (uint32_t*)(GPIO_BASE + 0x08);   // GPIO function select (for GPIO 21)
volatile uint32_t* GPSET0       = (uint32_t*)(GPIO_BASE + 0x1C);   // GPIO set (turn ON)
volatile uint32_t* GPCLR0       = (uint32_t*)(GPIO_BASE + 0x28);   // GPIO clear (turn OFF)

#define LED_PIN   21u
#define LED_MASK  (1u << LED_PIN)

// Delays
void delay(unsigned int count) {
    while (count--){
        __asm("NOP");
    }
}

// Initialize UART0 (115200 baud, 8N1)
void uart_init() {
    *UART0_CR = 0;  // Disable UART

    // Set baud rate (115200)
    *UART0_IBRD = 26;  // Integer part
    *UART0_FBRD = 3;   // Fractional part

    // 8-bit, no parity, one stop bit (8N1)
    *UART0_LCRH = (1 << 4) | (1 << 5) | (1 << 6);

    // Enable UART (TX only)
    *UART0_CR = (1 << 0) | (1 << 8) | (1 << 9);
}

// Print a single character
void uart_putc(char c) {
    while (*UART0_FR & (1 << 5));  // Wait if TX FIFO is full
    *UART0_DR = c;
}

// Print a string
void uart_puts(const char* str) {
    while (*str) {
        uart_putc(*str++);
    }
}

// Main program
void main() {
    // Initialize UART
    uart_init();
    uart_puts("Hello, bare-metal world!\r\n");

    // Set GPIO 16 as output
    *GPFSEL1 &= ~((7 << 12) | (7 << 15)); 
    *GPFSEL1 |=  ((4 << 12) | (4 << 15));   /* ALT0 = 100    */

    *GPFSEL2 &= ~(0b111u << ((LED_PIN % 10u) * 3u));
    *GPFSEL2 |=  (0b001u << ((LED_PIN % 10u) * 3u));
    // Blink LED forever
    while (1) {
        *GPSET0 = LED_MASK;  // Turn ON
        uart_puts("LED ON\r\n");
        delay(0xFFFFFF);

        *GPCLR0 = LED_MASK; // Turn OFF
        uart_puts("LED OFF\r\n");
        delay(0xFFFFFF);
    }
}