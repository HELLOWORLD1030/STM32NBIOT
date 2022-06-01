#ifndef __TIMER_H
#define __TIMER_H
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
extern unsigned int Count_timer_100ms_x_Collect_Interval;
extern unsigned char Count_timer_100ms_x_Send_Interval_after_collect;
extern unsigned char Count_Send_Time_Interval;
extern unsigned char count_time;
void TIM3_Int_Init(u16 arr,u16 psc);
#endif /* __TIMER_H */