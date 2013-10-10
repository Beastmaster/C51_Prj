#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

void DelayMS(uint ms)
{
	uchar i;
	while(ms--)
		for(i=0;i<120;i++);
}
  //向串口发送字符
void putc_serial(uchar c)
{
	SBUF=c;
	while(TI==0);
	TI=0;
}

 //向串口发送字符串
void puts_serial(char*s)
{
	while(*s!='\0')
	{
		putc_serial(*s);
		s++;
		DelayMS(5);
	}
}

void main()
{
	uchar c=0;
	SCON=0X40;	   //串口模式1
	TMOD=0X20;//T1工作模式2
	TH1=0Xfd;  //波特率9600
	TL1=0xfd;
	PCON=0X00; //波特率不倍增
	TI=0;
	TR1=1;
	DelayMS(200);

	//向主机发送数据
	puts_serial("receiving form 80c51..\r\n");
	puts_serial("---------------\r\n");
	DelayMS(50);
	while(1)
	{
		putc_serial(c+'A');
		DelayMS(100);
		putc_serial(' ');
		DelayMS(100);
		if(c==25)
		{
			puts_serial("\r\n-----------\r\n");
			DelayMS(100);
		}
		c=(c+1)%26;
		if(c%10==0)
		{
			puts_serial("\r\n");
			DelayMS(100);
		}
	}
}





/*#include<reg52.h>

unsigned char flag,a,i;
unsigned char table[]="I get ";

void inits()
{
	TMOD=0X20;
	TH1=0Xfd;
	TL1=0Xfd;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
}		 

void main()
{	
	inits();
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			for(i=0;i<6;i++)
			{
				SBUF=table[i];
				while(!TI)
				TI=0;
			}
			SBUF=a;
			while(!TI);
			TI=0;
			ES=1;
			flag=0;
		}
	}
}

void ser() interrupt 4
{
	RI=0;
	a=SBUF;
	flag=1;
}
	  */

