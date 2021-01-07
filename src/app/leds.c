/***********************************************************************************************************************
* File Name    : leds.c
* Version      : v01
* Device(s)    : R5F100LG
* Tool-Chain   : CCRL
* Description  : This file control led flash.
* Creation Date: 2020/12/30
***********************************************************************************************************************/

#include "include.h"


int8u  ucled_one_time;
int8u  ucled_two_time;
int8u  ucled_three_time;
int8u  ucone_ctl_flag;
int8u  uctwo_ctl_flag;
int8u  ucthree_ctl_flag;

/***********************************************************************************************************************
* Function Name: LedOneTime
* Description  : This function adds first led times.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void LedOneTime(void)
{
    ucled_one_time ++;
    if (ucled_one_time > 10)
    {
        ucled_one_time = 0;
        ucone_ctl_flag = !ucone_ctl_flag;
    }
}

/***********************************************************************************************************************
* Function Name: LedTwoTime
* Description  : This function adds second led times.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void LedTwoTime(void)
{
    ucled_two_time ++;
    if (ucled_two_time > 10)
    {
        ucled_two_time = 0;
        uctwo_ctl_flag = !uctwo_ctl_flag;
    }
}

/***********************************************************************************************************************
* Function Name: LedThreeTime
* Description  : This function adds second led times.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void LedThreeTime(void)
{
    ucled_three_time ++;
    if (ucled_three_time > 10)
    {
        ucled_three_time = 0;
        ucthree_ctl_flag = !ucthree_ctl_flag;
    }
}

/***********************************************************************************************************************
* Function Name: LedTimeCalc10ms
* Description  : This function is 10ms times calc.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void LedTimeCalc10ms(void)
{
    LedOneTime();
}

/***********************************************************************************************************************
* Function Name: LedTimeCalc
* Description  : This function is 100ms times calc.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void LedTimeCalc100ms(void)
{
    LedTwoTime();
}

/***********************************************************************************************************************
* Function Name: LedTimeCalc1s
* Description  : This function is 1s times calc.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void LedTimeCalc1s(void)
{
    LedThreeTime();
}

/***********************************************************************************************************************
* Function Name: TaskLeds
* Description  : This function control led flash onece 1s a time.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void TaskLeds(void)
{
    LED_ONE = ucone_ctl_flag;
    LED_TWO = uctwo_ctl_flag;
    LED_THREE = ucthree_ctl_flag;
}

