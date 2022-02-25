/*
Steps to get LED to work

1/ Identify the GPIO Pin
    - PA5
2/ Identify the bus
    - AHB1
3/ Enable GPIOA using Reset and clock Control Register
    - RCC_AHB1ENR - to enable
    - RCC_AHB1RSTR - to reset
4/ Configure GPIOA register
    - MODER - Sets up mode of the pin - to output
    - ODR - Output Data Register
*/

#include "main.h"

#include <stdint.h>

void delay(int count) {
  for (int i = 0; i < count; i++)
    ;
}

int main(void) {
  RCC_AHB1ENR = 1;    // Enable GPIOA
  RCC_AHB1RSTR |= 1;  // Reset GPIOA
  RCC_AHB1RSTR = 0;
  GPIOA_MODER |= GPIOA5;  // Set pin A5 in output mode
                          // (bit 10 needs to enable)
  GPIOA_ODR |= LD2_ON;    // Set A5 pin high to turn on the LED

  while (1) {
    delay(1000000);
    GPIOA_ODR &= LD2_OFF;
    delay(1000000);
    GPIOA_ODR |= LD2_ON;
  }
  return 0;
}
