/*
 * hardware.c
 *
 *  Created on: 20. maj 2017
 *      Author: simon
 */

#include "hardware.h"
#include "gpio.h"
#include "systick_frt.h"

void setupHardware(void)
/*****************************************************************************
*   Input    :  -
*   Output   :  -
*   Function :
*****************************************************************************/
{
  // TODO: Put hardware configuration and initialisation in here

  // Warning: If you do not initialize the hardware clock, the timings will be inaccurate
  init_systick();
  initGPIO();

}
