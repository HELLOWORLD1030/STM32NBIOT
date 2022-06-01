#ifndef __USART_H
#define __USART_H
#include "stm32f10x.h"
#include "stdio.h"
#include "sys.h" 
#include "stdbool.h"
//////////////////////////////////////////////////////////////////////////////////
#define USART1_REC_LEN 500
#define USART_REC_LEN 500 //定义最大接收字节数 500
#define EN_USART1_RX 1 //使能（1）/禁止（0）串口 1 接收
extern u8 USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大 USART_REC_LEN 个字节.末字节为换行符
extern u16 USART1_RX_STA; //接收状态标记
extern u16 USART2_RX_STA; //接收状态标记
extern char USART1_RX_BUF[USART1_REC_LEN]; //接收缓冲,最大 USART_REC_LEN 个字节.
extern unsigned char USART2_RX_BUF[USART_REC_LEN]; //接收缓冲,最大 USART_REC_LEN 个字节.末字节为行符
extern unsigned char USART3_RX_BUF[USART_REC_LEN]; //接收缓冲,最大 USART_REC_LEN 个字节.
extern bool Flag_Usart1_Receive;
extern bool Flag_Usart2_Receive;
extern bool Flag_usart1_receive_OK;
extern bool Flag_usart1_receive_T;
extern bool Flag_usart2_receive_T;
extern unsigned char Count_Timer3_value_USART1_receive_timeout;
extern unsigned char Count_Timer3_value_USART2_receive_timeout;
extern unsigned char Count_time_wait_ok;
void Usart1_Init(u32 bound);
void Usart1_Remap_Init(u32 bound);
void USART1TxChar(char ch);
void USART1TxData(unsigned char *pt);
void USART1TxStr(char *pt);
void USART1_IRQHandler(void);
void CLR_Buf1(void);
void Usart2_Init(u32 bound);
void Usart2_Remap_Init(u32 bound);
static void USART2_RCC_Configuration(void);
static void USART2_GPIO_Configuration(void); 
static void USART2_Configuration(u32 bound); 
static void USART2_NVIC_Configuration(void);
void USART2TxChar(int ch);
void USART2TxData(unsigned char *pt);
void USART2TxData_hex(unsigned char *pt,unsigned char len);
void USART2TxStr(char *pt);
void CLR_Buf2(void); //清除串口 2 接收缓存
#endif