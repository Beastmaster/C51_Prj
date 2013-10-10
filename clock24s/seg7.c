/*
 *	Copyright (C) 2006, ���пƼ���ѧ��������ӿƼ���������
 *	All Rights Reserved.
 *	
 *	�ļ���:		seg7.c
 *	�ļ�����:	8������������������ļ�
 *			
 *	��ǰ�汾:	1.0
 *	����:		SangWei(swkyer@gmail.com)
 *	�������:	2005��12��12��
 *	
*/
#include <reg51.h>
#include <INTRINS.H>
//#include "..\key1\main.h"


/* ����� */
unsigned char code seg_code[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,	// 0--9
								 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};	// A, b, C, d, E, F, ����


/**************************************
˵��:	д��������
seg:	����ʾ�Ķ�������, 0-9, A-F
**************************************/
void WriteSegData(unsigned char seg)
{
	/* Խ���жϣ������Ҷ�Ӧ�Ķ��� */
	if(seg > 16)
		seg = 16;
	seg = seg_code[seg];
	/* �����������͵����������� */
	P0 = seg;
	/* �ȴ������ȶ� */
	_nop_();
	_nop_();

	P2 &= 0x1F;	/* P2.5-P2.7 = 000, ����138��������ʹƬѡ�ź�CS0=0 */

	/* ��ʱ��ά��CS0Ϊ�͵�ƽ */
	_nop_();
	_nop_();


	P2 |= 0xE0;	/* P2.5-P2.7 = 111, CS0=1, �������������壬�����������ϵ��������� */
}

/**************************************
˵��:	дλѡ����
cs:		cs����λΪλѡλ��1: ��Ч��0: ��Ч
**************************************/
void WriteCsData(unsigned char cs)
{

	cs &= 0x0F;	/* ����λ��Ч�����θ���λ */	

	P0 = ~cs;  /* cs�ź�Ϊ����Ч����cs����������������� */

	/* �ȴ������ȶ� */
	_nop_();
	_nop_();

	/* P2.5 = 0, P2.6-P2.7 = 0, ����138��������ʹƬѡ�ź�CS1 = 0 */
	P2 &= 0x3F;
	/* ��ʱ��ά��CS1Ϊ�͵�ƽ */
	_nop_();
	_nop_();
	/* P2.5-P2.7 = 111, CS0=1, �������������壬�����������ϵ��������� */
	P2 |= 0xE0;
}