/*
 *	Copyright (C) 2006, 华中科技大学电气与电子科技创新中心
 *	All Rights Reserved.
 *	
 *	文件名:		smc162.c
 *	文件描述:	16*2字符液晶驱动主文件
 *			
 *	当前版本:	1.0
 *	作者:		ZhangLi(zhangli.xing@gmail.com)
 *	完成日期:	2005年12月12日
 *	
*/
#include "SMC162.h"
#include "reg51.h"

/***************************************
说明: 	LCD写函数,完成LCD写操作的物理时序
value:	写的具体值
RS:		0 - 写指令
		1 - 写数据
*****************************************/
void LcdWrite(unsigned char value , bit RS)
{
	/* 1. 设置RS信号线 */
	Lcd_RS = RS ;
	/* 2. 设置RW信号线为读 */
	Lcd_RW = 0 ;
	/* 3. 设置LCD片选 */
	SELECT_LCD();
	/* 4. 通过P0端口写值 */
	P0 = value ;
	/* 5. 锁存 */
	SELECT_NONE();
}

/***************************************
说明: 	LCD读函数,完成LCD读操作的物理时序
RS:		0 - 写指令
		1 - 写数据
return:	读出的具体值
*****************************************/
unsigned char LcdRead(bit RS)
{
	unsigned char rt ;

	/* 1. 设置RS信号线 */
	Lcd_RS = RS ;
	/* 2. 设置RW信号线为读 */
	Lcd_RW = 1 ;
	/* 3. 释放P0口 */
	P0 = 0xff ;
	/* 4. 设置LCD片选 */
	SELECT_LCD();
	SELECT_LCD();
	SELECT_LCD();
	SELECT_LCD();
	/* 5. 通过P0端口读值 */
	rt = P0 ;
	/* 6. 锁存 */
	SELECT_NONE();

	return rt ;
}	

/***************************************
说明: 	LCD写指令
value:	写的具体值
attrib:	0 - 不检测忙信号
	   	1 - 监测忙信号
*****************************************/
void LcdWriteCmd(unsigned char value , unsigned char attrib)
{
	/* 监测忙状态 */
	if(attrib)
		while( LcdRead(0)&0x80 ) ;
	
	LcdWrite(value , 0);
 }

/***************************************
说明: 	LCD写数据
*****************************************/
void LcdWriteData(unsigned char value)
{
 	/* 监测忙状态 */
	while( LcdRead(0)&0x80 ) ;

	LcdWrite(value , 1);
}

/***************************************
说明: 	LCD读数据
*****************************************/
unsigned char LcdReadData()
{
	/* 监测忙状态 */
	while( LcdRead(0)&0x80 ) ;

	return LcdRead(1);
}

/***************************************
说明: 	短延时, 5ms
*****************************************/
void Delay5Ms(void)
{
	unsigned int i = 5552;
	while(i--);
}

/***************************************
说明: 	长延时 , 400ms
*****************************************/
void Delay400Ms(void)
{
	unsigned char i = 80;
	while(i--)
		Delay5Ms();
}
/***************************************
说明: 	LCD初始化函数,需要按照产品
        说明书完成
*****************************************/
void LcdInit(void)
{
	Delay400Ms();	

	/* 写指令0x38连续3次, 不检测忙信号*/
	LcdWriteCmd(0x38 , 0 );
	Delay5Ms();

	LcdWriteCmd(0x38 , 0 );
	Delay5Ms();

	LcdWriteCmd(0x38 , 0 );
	Delay5Ms();

	/* 以后的读写操作均要判断忙信号 */
	LcdWriteCmd(0x38 , 1 );
	/* 先设置关屏 */
	LcdWriteCmd(0x08 , 1 );
	/* 清屏 */
	LcdWriteCmd(0x01 , 1 );
	/* 设置光标显示模式 */
	LcdWriteCmd(0x06 , 1 );
	/* 开屏并显示光标 */
	LcdWriteCmd(0x0c , 1 );
}

/***************************************
说明: 	设置光标定位
*****************************************/
void LocateXY(char x , char y)
{
	unsigned char temp;

	temp = x & 0xf;
	y &= 0x1;
	if ( y )temp |= 0x40;
	temp |= 0x80;
	LcdWriteCmd(temp,1);
}

/***************************************
说明: 	显示字符
x: 横坐标 y: 纵坐标
value: 显示的字符
*****************************************/
void PutChar(char x , char y , char value)
{
	LocateXY(x,y);
	LcdWriteData(value);
}

/***************************************
说明: 	显示字符串
*****************************************/
void PutStr(char x , char y , char* str)
{
	unsigned char i,len=0;
	/* 计算字符串长度 */
	while (str[len] >31)
		len++;
	
	/* 显示字符串 */
	for (i=0;i<len;i++) 
	{
		PutChar(x++,y,str[i]);
		if ( x == 16 )
		{
			x = 0; y ^= 1;
		}
	}
}


