/*
 *	Copyright (C) 2006, ���пƼ���ѧ��������ӿƼ���������
 *	All Rights Reserved.
 *	
 *	�ļ���:		smc162.c
 *	�ļ�����:	16*2�ַ�Һ���������ļ�
 *			
 *	��ǰ�汾:	1.0
 *	����:		ZhangLi(zhangli.xing@gmail.com)
 *	�������:	2005��12��12��
 *	
*/
#include "SMC162.h"
#include "reg51.h"

/***************************************
˵��: 	LCDд����,���LCDд����������ʱ��
value:	д�ľ���ֵ
RS:		0 - дָ��
		1 - д����
*****************************************/
void LcdWrite(unsigned char value , bit RS)
{
	/* 1. ����RS�ź��� */
	Lcd_RS = RS ;
	/* 2. ����RW�ź���Ϊ�� */
	Lcd_RW = 0 ;
	/* 3. ����LCDƬѡ */
	SELECT_LCD();
	/* 4. ͨ��P0�˿�дֵ */
	P0 = value ;
	/* 5. ���� */
	SELECT_NONE();
}

/***************************************
˵��: 	LCD������,���LCD������������ʱ��
RS:		0 - дָ��
		1 - д����
return:	�����ľ���ֵ
*****************************************/
unsigned char LcdRead(bit RS)
{
	unsigned char rt ;

	/* 1. ����RS�ź��� */
	Lcd_RS = RS ;
	/* 2. ����RW�ź���Ϊ�� */
	Lcd_RW = 1 ;
	/* 3. �ͷ�P0�� */
	P0 = 0xff ;
	/* 4. ����LCDƬѡ */
	SELECT_LCD();
	SELECT_LCD();
	SELECT_LCD();
	SELECT_LCD();
	/* 5. ͨ��P0�˿ڶ�ֵ */
	rt = P0 ;
	/* 6. ���� */
	SELECT_NONE();

	return rt ;
}	

/***************************************
˵��: 	LCDдָ��
value:	д�ľ���ֵ
attrib:	0 - �����æ�ź�
	   	1 - ���æ�ź�
*****************************************/
void LcdWriteCmd(unsigned char value , unsigned char attrib)
{
	/* ���æ״̬ */
	if(attrib)
		while( LcdRead(0)&0x80 ) ;
	
	LcdWrite(value , 0);
 }

/***************************************
˵��: 	LCDд����
*****************************************/
void LcdWriteData(unsigned char value)
{
 	/* ���æ״̬ */
	while( LcdRead(0)&0x80 ) ;

	LcdWrite(value , 1);
}

/***************************************
˵��: 	LCD������
*****************************************/
unsigned char LcdReadData()
{
	/* ���æ״̬ */
	while( LcdRead(0)&0x80 ) ;

	return LcdRead(1);
}

/***************************************
˵��: 	����ʱ, 5ms
*****************************************/
void Delay5Ms(void)
{
	unsigned int i = 5552;
	while(i--);
}

/***************************************
˵��: 	����ʱ , 400ms
*****************************************/
void Delay400Ms(void)
{
	unsigned char i = 80;
	while(i--)
		Delay5Ms();
}
/***************************************
˵��: 	LCD��ʼ������,��Ҫ���ղ�Ʒ
        ˵�������
*****************************************/
void LcdInit(void)
{
	Delay400Ms();	

	/* дָ��0x38����3��, �����æ�ź�*/
	LcdWriteCmd(0x38 , 0 );
	Delay5Ms();

	LcdWriteCmd(0x38 , 0 );
	Delay5Ms();

	LcdWriteCmd(0x38 , 0 );
	Delay5Ms();

	/* �Ժ�Ķ�д������Ҫ�ж�æ�ź� */
	LcdWriteCmd(0x38 , 1 );
	/* �����ù��� */
	LcdWriteCmd(0x08 , 1 );
	/* ���� */
	LcdWriteCmd(0x01 , 1 );
	/* ���ù����ʾģʽ */
	LcdWriteCmd(0x06 , 1 );
	/* ��������ʾ��� */
	LcdWriteCmd(0x0c , 1 );
}

/***************************************
˵��: 	���ù�궨λ
*****************************************/
void LocateXY(char x , char y)
{
	unsigned char temp;

	temp = x & 0xf;
	y &= 0x1;
	if ( y )temp |= 0x40;
	temp |= 0x80;
	LcdWriteCmd(temp,1);
}

/***************************************
˵��: 	��ʾ�ַ�
x: ������ y: ������
value: ��ʾ���ַ�
*****************************************/
void PutChar(char x , char y , char value)
{
	LocateXY(x,y);
	LcdWriteData(value);
}

/***************************************
˵��: 	��ʾ�ַ���
*****************************************/
void PutStr(char x , char y , char* str)
{
	unsigned char i,len=0;
	/* �����ַ������� */
	while (str[len] >31)
		len++;
	
	/* ��ʾ�ַ��� */
	for (i=0;i<len;i++) 
	{
		PutChar(x++,y,str[i]);
		if ( x == 16 )
		{
			x = 0; y ^= 1;
		}
	}
}


