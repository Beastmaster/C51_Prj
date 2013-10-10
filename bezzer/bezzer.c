#include<reg51.h>

#include"SMC162.h"


#define BEEP_PIN 0x10
#define DELAY_TIME 50

void delay(unsigned char dly)
{
	unsigned char j;
	for(j=dly;j>0;j--)
		;
}

void main(void)
{
	while(1)
	{
		P1^=BEEP_PIN;
		delay(DELAY_TIME);
		PutStr(0 , 1 , "chastr");
	}
}