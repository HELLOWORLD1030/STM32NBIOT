#include "gpio.h"
void GPIO_Configuration(void)//GPIO 初始化
{
GPIO_InitTypeDef GPIO_InitStructure; 
/*初始化结构体*/ 
GPIO_StructInit(&GPIO_InitStructure);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能 PA 端口时钟
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//使能 PC 端口时钟
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);//使能 PC 端口时钟
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化 PA.0
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化 PA.1
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化 PA.4，控制 NB 模块开关
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化 PB.5，控制传感器开关
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOC, &GPIO_InitStructure); //初始化 PC.13，控制红色 R_LED
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOC, &GPIO_InitStructure); //初始化 PC.14，控制绿色 G_LED
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//普通推挽输出
GPIO_Init(GPIOC, &GPIO_InitStructure); //初始化 PC.15，控制黄色 Y_LED
R_LED_OFF;
G_LED_OFF;
Y_LED_OFF;
}
