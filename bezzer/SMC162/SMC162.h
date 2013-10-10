/*
 *	Copyright (C) 2006, 华中科技大学电气与电子科技创新中心
 *	All Rights Reserved.
 *	
 *	文件名:		main.c
 *	文件描述:	16*2字符液晶测试主程序文件
 *			
 *	当前版本:	1.0
 *	作者:		ZhangLi(zhangli.xing@gmail.com)
 *	完成日期:	2005年12月12日
 *	
*/
#ifndef _SMC162_H_
#define _SMC162_H_

#include <REGX52.H>

sbit CS0 = P2^5 ;
sbit CS1 = P2^6 ;
sbit CS2 = P2^7 ;

#define SELECT_LCD()	CS0=0; CS1=1; CS2=0
#define SELECT_NONE()	CS0=1; CS1=1; CS2=1

sbit Lcd_RW = P2^4 ;
sbit Lcd_RS = P2^3 ;

/*******************  函数声明 ********************/
void LcdWrite(unsigned char value , bit RS);
unsigned char LcdRead(bit RS);
void LcdWriteCmd(unsigned char value , unsigned char attrib);
void LcdWriteData(unsigned char value);
unsigned char LcdReadData();
void Delay5Ms(void);
void Delay400Ms(void);
void LcdInit(void);
void LocateXY(char x , char y);
void PutChar(char x , char y , char value);
void PutStr(char x , char y , char* str);

#endif
	