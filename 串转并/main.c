#include <reg51.h>
sbit LED=P1;
sbit input=P2^0;

void main()
{
	int buf=0;
	LED=0X00;	

	while(1)
	{
		if(buf==input)
		{
			Led++;
		}
	//	buf=buf+input;
		delay(50);
	//	LED=buf;
		delay(50);	
	}

}


void delay(uint ms)
{
	uchar i;
	 while(ms--)
	 	for(i=0;i<120;i++)
		;
}







/*#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define	uint unsigned int
sbit SPK=P3^7;
uchar FRQ=0x00;

void delay(uint ms)
{
	uchar i;
	 while(ms--)
	 	for(i=0;i<120;i++)
		;
}

void main()
{
	uchar c=0x80;
	SCON=0x00;
	TI=1;
	while(1)
	{
		c=_crol_(c,1);
		SBUF=c;
		while(TI==0);
		TI=0;
		delay(400);
		P1=c;
	}
}

		  */













