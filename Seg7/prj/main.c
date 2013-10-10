/*
 *	Copyright (C) 2006, 华中科技大学电气与电子科技创新中心
 *	All Rights Reserved.
 *	
 *	文件名:		main.c
 *	文件描述:	8段数码管测试程序主文件
 *			
 *	当前版本:	1.0
 *	作者:		SangWei(swkyer@gmail.com)
 *	完成日期:	2005年12月12日
 *	
*/



//没有用定时器

#include <reg51.h>
#include <INTRINS.H>
#include "..\seg7\seg7.h"
#include "..\key1\main.h"

/* 定时时间高低字节数据 */
#define TIMERH		0xEF
#define TIMERL		0xFF

unsigned char cs=0;			 //全局变量cs，位选
unsigned char dispram[4];

//void delay(unsigned char dly);   //头文件main.h中

//void InitTimer(void);
 
void display(); 
 //显示函数
 void display()
{
		if(cs >= 3)
			cs = 0;
    	else
			cs++;
    
		WriteSegData(dispram[cs]);	  //段选 写数据
    	WriteCsData(1<<cs);	          //位选  写数据

    	delay(5);
 		
}





void main(void)
{
	int x=0,y=0;
	P0 = 0xFF;
	P2 = 0xFF;

//	InitTimer();

	/* 启动定时器1 */
//	TR1 = 1;

	dispram[0] = 0;
	dispram[1] = 8;
	dispram[2] = 7;
	dispram[3] = 9;
	
	while(1)
	{

	display();
	
//	if(keyscan()) 
//	  dispram[0]++;

   /* 	if(cs >= 3)
		cs = 0;
    	else
		cs++;
    	WriteSegData(dispram[cs]);	  //段选 写数据
    	WriteCsData(1<<cs);	          //位选  写数据

    	delay(5);		 */
 	
	 }
	 ;
/*	{
		dispram[x++]++;
		delay();
		if(x==3)
			x=0;
	};	*/
}

/**************************************
说明:	简单延时程序  
dly:	延时时间参数
**************************************/
void delay(unsigned char dly)
{
	unsigned char i, j;

	for(i=10; i>0; i--)
		for(j=dly; j>0; j--);
}


/**************************************
说明:	定时器初始化
		定时时间10mS
**************************************/
/* 
void InitTimer(void)
{
	// 变量初始化 
	cs = 0;
	dispram[0] = dispram[1] = dispram[2] = dispram[3] = 0;
	// 初始化定时器，定时时间10mS，允许定时器中断 
	TMOD = 0x90;
	TH1 = TIMERH;
	TL1 = TIMERL;
//	 开定时器中断 
	EA = 1;
	ET1 = 1;
}	*/		 

/**************************************
说明:	定时器中断处理函数
**************************************/
/*
void Timer1ISR(void) interrupt 3 using 2
{
	// 定时器重装 
	TH1 = TIMERH;
	TL1 = TIMERL;
	//* 清中断标志 
	TF1 = 0;
	// 循环显示 
	if(cs >= 3)
		cs = 0;
	else
		cs++;
	WriteSegData(dispram[cs]);	  //段选 写数据
	WriteCsData(1<<cs);	          //位选  写数据
}
	  */