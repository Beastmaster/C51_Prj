#include <reg51.h>
#include <INTRINS.H>
#include "seg7.h"
#include <main.h>
#include <stdio.h>
#include <math.h>

sbit key1				//模式选择键
sbit key2				//数字加
sbit buzzer				//蜂鸣器




unsigned char hour=0,min=0,sec=0;
unsigned char day=0,month=0,year=0;

unsigned char mode=0;	//模式标志


int main(void)
{
	int i,j;

	EA=1;            //开总中断
	ET0=1;           //定时器0使能	
 //启动定时器！！
	TR0=1;           //定时器启动




//时分秒进位	
	if(sec==59)
	 {
		if(min==59)
			{
				if(hour==24)
					hour==0;
				else 
					hour++;
			}
		else
			min++;
	  }
     else
		sec++;

//模式选择
	if(!key1)
		if(mode==4)
			mode++;	

//



}







void delay(int x)
{
	int i,j;
	for(i=0;i<100;i++)
		for(j=0;j<x;j++);
	return 0;
}



//用中断计秒
void second() interruput 0 
{
	InitTimer();
	if(sec==59)
		sec=0;
	else 
		sec++;	
	

}

//初始化定时器
void InitTimer1()
{
	TMOD=0X21;      //定时器0，方式1
	TH0=*****;       //高位
	TL0=****;		 //低位
	TR=0;			//中断标志清零
}




