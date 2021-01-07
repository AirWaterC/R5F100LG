/***********************************************************************************************************************
* File Name    : leds.h
* Version      : v01
* Device(s)    : R5F100LG
* Tool-Chain   : CCRL
* Description  : This file control led flash.
* Creation Date: 2020/12/30
***********************************************************************************************************************/

#ifndef __LEDS_H__
#define __LEDS_H__


#define LED_ONE    P4_bit.no1
#define LED_TWO    P4_bit.no2
#define LED_THREE  P4_bit.no3


//out file interface, do not change
void LedTimeCalc10ms(void);
void LedTimeCalc100ms(void);
void LedTimeCalc1s(void);
void TaskLeds(void);





#endif

