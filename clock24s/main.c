#include"reg51.h"
#include"seg7.h"
#include <INTRINS.H>


sbit beep1=P1^4;
sbit pluse=P1^7;


unsigned char cs=0;			 //ȫ�ֱ���cs��λѡ
unsigned char dispram[4];



void delay(unsigned char dly);		  //��ʱ����
void beep();				//������
void display();    			//��ʾ����
void break1();				//��ͣ����



//������
int main(void)
{

 	 int clk=0 ;
	 int min,sec;		   //����֡���

	 min=0;
	 sec=0;
	 
	dispram[0]=0;
	dispram[1]=0;

	display();

	while(1)
	{
		if(pluse==1)
			continue;
		else
			break;
	}

	 delay(180);

	 while(1)
	 {
		clk++;				   //��Ƶ
		sec=clk/200;
		min=sec/10;

		if(min==2)
		{
			if(sec%10==4)
		   {	beep();
			dispram[0]=4;
			dispram[1]=2; }
		}

		//��ʾ	
		dispram[0] = sec%10;
		dispram[1] = min%10;
		dispram[2]=0;
		dispram[3]=0;
		display();


			//��ͣ
		if(pluse==0)
		{	
			delay(150);	
			while(1)
			{				
				display();
				if(pluse==0)
					{delay(150);
					break;}
			}
		}

	 }
}

//��ʱ����
void delay(unsigned char dly)
{
	unsigned char i, j;

	for(i=100; i>0; i--)
		for(j=dly; j>0; j--);
}

//������
void beep()
{
	beep1=1;
	while(1)
	{
		beep1=~beep1;
		delay(1);
	}
}

// �������ʾ
 void display()
{
		if(cs >= 3)
			cs = 0;
    	else
			cs++;
    
		WriteSegData(dispram[cs]);	  //��ѡ д����
    	WriteCsData(1<<cs);	          //λѡ  д����

    	delay(5);		
}

void break1()
{
	if(pluse==1)
	{
		delay(5);
		while(1)
		{
			if(pluse==1)
				break;
			else
				continue;
		}
	}
	else
	;
}




