// TI MSP430 LED Blinking
#include <msp430.h>

int main(void) {
  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
  P1DIR |= 0x01;            // Set P1.0 to output direction

  while (1) {
    P1OUT = 0x01;                     // LED ON
    __delay_cycles(1000000);   // Wait 1 sec
    P1OUT = 0x00;                     // LED OFF
    __delay_cycles(1000000);  // Wait 1 sec
  }
}