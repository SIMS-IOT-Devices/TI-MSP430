#include <msp430.h>

void main(void) {
  WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

  // Configure clock
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;

  // Configure UART pins
  P1SEL |= BIT1 + BIT2; // P1.1 = RXD, P1.2 = TXD
  P1SEL2 |= BIT1 + BIT2;

  // Configure USCI_A0
  UCA0CTL1 |= UCSSEL_2; // SMCLK
  UCA0BR0 = 104;        // 1MHz 9600
  UCA0BR1 = 0;
  UCA0MCTL = UCBRS0;    // Modulation
  UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine

  // Transmit a character
  while (1) {
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = 'T';
    __delay_cycles(1000000); // Wait 1 sec
  }
}
