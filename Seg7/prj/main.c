/*
 *	Copyright (C) 2006, ���пƼ���ѧ��������ӿƼ���������
 *	All Rights Reserved.
 *	
 *	�ļ���:		main.c
 *	�ļ�����:	8������ܲ��Գ������ļ�
 *			
 *	��ǰ�汾:	1.0
 *	����:		SangWei(swkyer@gmail.com)
 *	�������:	2005��12��12��
 *	
*/



//û���ö�ʱ��

#include <reg51.h>
#include <INTRINS.H>
#include "..\seg7\seg7.h"
#include "..\key1\main.h"

/* ��ʱʱ��ߵ��ֽ����� */
#define TIMERH		0xEF
#define TIMERL		0xFF

unsigned char cs=0;			 //ȫ�ֱ���cs��λѡ
unsigned char dispram[4];

//void delay(unsigned char dly);   //ͷ�ļ�main.h��

//void InitTimer(void);
 
void display(); 
 //��ʾ����
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





void main(void)
{
	int x=0,y=0;
	P0 = 0xFF;
	P2 = 0xFF;

//	InitTimer();

	/* ������ʱ��1 */
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
    	WriteSegData(dispram[cs]);	  //��ѡ д����
    	WriteCsData(1<<cs);	          //λѡ  д����

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
˵��:	����ʱ����  
dly:	��ʱʱ�����
**************************************/
void delay(unsigned char dly)
{
	unsigned char i, j;

	for(i=10; i>0; i--)
		for(j=dly; j>0; j--);
}


/**************************************
˵��:	��ʱ����ʼ��
		��ʱʱ��10mS
**************************************/
/* 
void InitTimer(void)
{
	// ������ʼ�� 
	cs = 0;
	dispram[0] = dispram[1] = dispram[2] = dispram[3] = 0;
	// ��ʼ����ʱ������ʱʱ��10mS������ʱ���ж� 
	TMOD = 0x90;
	TH1 = TIMERH;
	TL1 = TIMERL;
//	 ����ʱ���ж� 
	EA = 1;
	ET1 = 1;
}	*/		 

/**************************************
˵��:	��ʱ���жϴ�����
**************************************/
/*
void Timer1ISR(void) interrupt 3 using 2
{
	// ��ʱ����װ 
	TH1 = TIMERH;
	TL1 = TIMERL;
	//* ���жϱ�־ 
	TF1 = 0;
	// ѭ����ʾ 
	if(cs >= 3)
		cs = 0;
	else
		cs++;
	WriteSegData(dispram[cs]);	  //��ѡ д����
	WriteCsData(1<<cs);	          //λѡ  д����
}
	  */