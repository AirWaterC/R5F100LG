/***********************************************************************************************************************
* File Name    : buzzer.c
* Version      : v01 
* Device(s)    : R5F100LG
* Tool-Chain   : CCRL
* Description  : buzzer contorl.
* Creation Date: 2020/12/31
***********************************************************************************************************************/

#include "include.h"

int8u ucbuzzer_time;
int8u uctimes;      //鸣叫10次后不再鸣叫
int8u ucbuzzer_flag;


/***********************************************************************************************************************
* Function Name: BuzzerTime
* Description  : This function adds buzzer open time, 10ms call onece time.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void BuzzerTime(void)
{
    if (uctimes < 2)
    {
		ucbuzzer_time ++;
		if (ucbuzzer_time >= 110)
		{
			ucbuzzer_time = 0;
			ucbuzzer_flag = FALSE;
			uctimes ++;
		}
		else if (ucbuzzer_time >= 10)
		{
			ucbuzzer_flag = FALSE;
		}
		else
		{
			ucbuzzer_flag = TRUE;
		}
    }
    else
    {
    	ucbuzzer_flag = FALSE;
    }
}

/***********************************************************************************************************************
* Function Name: TaskBuzzerCtl
* Description  : This function control buzzer on or off.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void TaskBuzzerCtl(void)
{
    if (ucbuzzer_flag)
    {
        R_PCLBUZ0_Start();
    }
    else
    {
        R_PCLBUZ0_Stop();
    }
}



