#include<reg51.h>


sbit LED=P1^5;
sbit KEY=P1;

void delay(unsigned int i)
{
	int x;
	for(x=0;x<=i;x++)  ;
		for(x=0;x<=100;x++);
}

void init_timer()
{
	EA=1;

}


void main()
{
	char led1=0xff;
	char led2=0x00;
	while(1)
	{
		LED=led1;
		delay(500);
		LED=led2;
		delay(500);
	}
}