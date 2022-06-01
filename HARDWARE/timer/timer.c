#include "timer.h"
#include "usart.h"
#define Time_Send_interval 5 // x * 100 毫秒
unsigned int Count_timer_100ms_x_Collect_Interval = 65530;//默认先不触发采集计时
unsigned char Count_timer_100ms_x_Send_Interval_after_collect = 201;//默认不触发发送计时
unsigned char Count_wait_ok = 0;
unsigned char Count_Flag_Flag_4Gmodel_ready = 100;
unsigned char Count_Send_Time_Interval = 0;
unsigned char count_time = 0;
unsigned char Count_time_wait_ok = 0;
bool Flag_allow_dsplay_time;
void TIM3_Int_Init(u16 arr,u16 psc)
{
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
NVIC_InitTypeDef NVIC_InitStructure;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
TIM_TimeBaseStructure.TIM_Period = arr;
TIM_TimeBaseStructure.TIM_Prescaler = psc;
TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_Init(&NVIC_InitStructure);
TIM_Cmd(TIM3, ENABLE);
}

void TIM3_IRQHandler(void)
{
if(TIM_GetITStatus(TIM3, TIM_IT_Update ) != RESET)
{
TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
if(Count_Timer3_value_USART2_receive_timeout)
Count_Timer3_value_USART2_receive_timeout --;
if(Count_Send_Time_Interval)
Count_Send_Time_Interval --;
if(Count_Timer3_value_USART1_receive_timeout)
Count_Timer3_value_USART1_receive_timeout --;
if(Count_Timer3_value_USART2_receive_timeout)
Count_Timer3_value_USART2_receive_timeout --;
if(count_time)
count_time --;
if(Count_time_wait_ok)
Count_time_wait_ok --;
if(Count_timer_100ms_x_Collect_Interval < 65530)
{
Count_timer_100ms_x_Collect_Interval ++;
Flag_allow_dsplay_time = 1;
}
if(Count_timer_100ms_x_Send_Interval_after_collect < 200)
{
Count_timer_100ms_x_Send_Interval_after_collect ++;
}
}

}
