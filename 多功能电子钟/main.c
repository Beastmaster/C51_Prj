#include <reg51.h>
#include <INTRINS.H>
#include "seg7.h"
#include <main.h>
#include <stdio.h>
#include <math.h>

sbit key1				//ģʽѡ���
sbit key2				//���ּ�
sbit buzzer				//������




unsigned char hour=0,min=0,sec=0;
unsigned char day=0,month=0,year=0;

unsigned char mode=0;	//ģʽ��־


int main(void)
{
	int i,j;

	EA=1;            //�����ж�
	ET0=1;           //��ʱ��0ʹ��	
 //������ʱ������
	TR0=1;           //��ʱ������




//ʱ�����λ	
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

//ģʽѡ��
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



//���жϼ���
void second() interruput 0 
{
	InitTimer();
	if(sec==59)
		sec=0;
	else 
		sec++;	
	

}

//��ʼ����ʱ��
void InitTimer1()
{
	TMOD=0X21;      //��ʱ��0����ʽ1
	TH0=*****;       //��λ
	TL0=****;		 //��λ
	TR=0;			//�жϱ�־����
}




