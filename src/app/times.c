/***********************************************************************************************************************
* File Name    : times.c
* Version      : v01
* Device(s)    : R5F100LG
* Tool-Chain   : CCRL
* Description  : This file implements system time.
* Creation Date: 2020/12/30
***********************************************************************************************************************/

#include "include.h"


unsigned char ucflage_10ms;
unsigned char ucflage_100ms;
unsigned char ucflage_1s;
unsigned char uctimes_10ms;
unsigned char uctimes_100ms;
unsigned char uctimes_1s;

/***********************************************************************************************************************
* Function Name: TimesCalc
* Description  : This function adds all times, and put up flag, 1ms interupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void TimesCalc(void)
{
    uctimes_10ms ++;
    if (uctimes_10ms >= 10)
    {
        uctimes_10ms = 0;
        ucflage_10ms = TRUE;

        uctimes_100ms ++;
        if (uctimes_100ms >= 10)
        {
            uctimes_100ms = 0;
            ucflage_100ms = TRUE;

            uctimes_1s ++;
            if (uctimes_1s >= 10)
            {
                uctimes_1s = 0;
                ucflage_1s = TRUE;
            }
        }
    }
}

/***********************************************************************************************************************
* Function Name: TaskTimes
* Description  : This function system time calc.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void TaskTimes(void)
{   //10ms
    if (TRUE == ucflage_10ms)
    {
        ucflage_10ms = FALSE;
        //10ms and add user task function
        LedTimeCalc10ms();
        BuzzerTime();
    }
    //100ms
    if (TRUE == ucflage_100ms)
    {
        ucflage_100ms = FALSE;
        //100ms and add user task function
        LedTimeCalc100ms();
    }
    //1s
    if (TRUE == ucflage_1s)
    {
        ucflage_1s = FALSE;
        //add user task function
        LedTimeCalc1s();
    }
}




