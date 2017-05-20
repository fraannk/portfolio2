/*
 * gpio.c
 *
 *  Created on: 20. maj 2017
 *      Author: simon
 */

/***************************** Include files *******************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "gpio.h"
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void initGPIO(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function : The super loop.
******************************************************************************/
{
  int dummy;

  // Enable the GPIO port that is used for the on-board LED.
  SYSCTL_RCGC2_R  = 0b00100010 | SYSCTL_RCGC2_GPIOD | SYSCTL_RCGC2_GPIOA | SYSCTL_RCGC2_GPIOC | SYSCTL_RCGC2_GPIOE;
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART0;

  // Do a dummy read to insert a few cycles after enabling the peripheral.
  dummy = SYSCTL_RCGC2_R;

  // Set the direction .
  GPIO_PORTA_DIR_R = 0x1C;
  GPIO_PORTC_DIR_R = 0xF0;
  GPIO_PORTD_DIR_R = 0x4C;
  GPIO_PORTE_DIR_R = 0x00;
  GPIO_PORTF_DIR_R = 0x0E;


  // Enable the GPIO pins for digital function.
  GPIO_PORTA_DEN_R = 0x1C;
  GPIO_PORTC_DEN_R = 0xF0;
  GPIO_PORTD_DEN_R = 0x4C;
  GPIO_PORTE_DEN_R = 0x0F;
  GPIO_PORTF_DEN_R = 0x0E;

  // Enable internal pull-up (PF0 and PF4).
  GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTF_DATA_R = 0x00; // turn on 3 LED's
  GPIO_PORTD_DATA_R &= ~(1<<0x40); // Status LED on


}
