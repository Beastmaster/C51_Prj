#include<reg51.h>
#include<intrins.h>
//sbit led=P1^1;

unsigned char num;

void main()
{
	P1=0x01;
	TMOD=0x01;
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	EA=1;
	ET0=1;
	TR0=1;
	while(1);
}

void T0_time() interrupt 1
{
	 TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	num++;
	if (num==20)
	{
		num=0;
		//led=~led;
		P1=_crol_(P1,1);
	}
}









/*#include<reg51.h>

void delay(unsigned char x);

sbit P1_0=P1^0;
sbit P1_5=P3^2;

int0(void) interrupt 0
{
	P1_0=P1_5;
	delay(100);
	P1_0=1;
}

void delay(char x)
{
	int j,i;
	for(j=0;j<300;j++)
		for(i=0;i<x;i++);
}



main(void)
{
//	EA=1;
	EX0=1;
	IT0=1;
	while(1)
		{
			delay(50);
			EA=1;
			EX0=1;
			IT0=1;
		};
}					   */