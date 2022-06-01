#ifndef __OLED_H
#define __OLED_H
#include "sys.h"
#include "stdlib.h" 
#define LCD_W 240
#define LCD_H 320
#define u8 unsigned char
#define u16 unsigned int
#define u32 unsigned long
#define OLED_MODE 0
#define SIZE 16
#define XLevelL 0x00
#define XLevelH 0x10
#define Max_Column 128
#define Max_Row 64
#define Brightness 0xFF 
#define X_WIDTH 128
#define Y_WIDTH 64 
//-----------------OLED ????---------------- 
#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_13)//CLK
#define OLED_SCLK_Set() GPIO_SetBits(GPIOB,GPIO_Pin_13)
#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_15)//DIN
#define OLED_SDIN_Set() GPIO_SetBits(GPIOB,GPIO_Pin_15)
#define OLED_RST_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_1)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define OLED_DC_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_0)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOB,GPIO_Pin_0) 
#define OLED_BLK_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_12)//CS
#define OLED_BLK_Set() GPIO_SetBits(GPIOB,GPIO_Pin_12)
#define OLED_CMD 0 //???
#define OLED_DATA 1 //???
extern u16 BACK_COLOR, POINT_COLOR; //???,???
void Lcd_Init(void); 
void LCD_WR_DATA8(char da); //????-8 ???
void LCD_WR_DATA(int da);
void LCD_WR_REG(char da);
void LCD_Clear(u16 Color);//??????,????????????????
void LCD_DrawPoint(u16 x,u16 y);
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode);
void LCD_ShowString(u16 x,u16 y,char *p); //???????,16 ??
void LCD_Show_One_Chinese16x16(unsigned int x,unsigned int y,const char *index);
void LCD_Show_Chinese16x16(unsigned int x,unsigned int y,char *index);
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
//????
#define WHITE 0xFFFF //?? //1
#define BLACK 0x0000 //?? //2
#define BLUE 0x001F //?? //3
#define BRED 0XF81F //??? //4
#define GRED 0XFFE0 //??? //5
#define GBLUE X07FF //??? //6
#define RED 0xF800 //?? //7
#define MAGENTA 0xF81F //?? //8
#define GREEN 0x07E0 //?? //9
#define CYAN 0x7FFF //?? //10
#define YELLOW 0xFFE0 //??? //11
#define BROWN 0XBC40 //??
#define BRRED 0XFC07 //???
#define GRAY 0X8430 //??
//GUI ??
#define DARKBLUE 0X01CF //???
#define LIGHTBLUE 0X7D7C //??? 
#define GRAYBLUE 0X5458 //???
//????? PANEL ???
#define LIGHTGREEN 0X841F //???
#define LGRAY 0XC618 //???(PANNEL),?????
#define LGRAYBLUE 0XA651 //????(?????)
#define LBBLUE 0X2B12 //????(???????)
#endif /* __OLED_H */