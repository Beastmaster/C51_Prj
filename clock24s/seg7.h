/*
 *	Copyright (C) 2006, ���пƼ���ѧ��������ӿƼ���������
 *	All Rights Reserved.
 *	
 *	�ļ���:		seg7.h
 *	�ļ�����:	8�����������ͷ�ļ�
 *			
 *	��ǰ�汾:	1.0
 *	����:		SangWei(swkyer@gmail.com)
 *	�������:	2005��12��12��
 *	
*/
#ifndef __SEG7_H__
#define __SEG7_H__

//sbit key=P1^5;

/* �������� */
void WriteSegData(unsigned char seg);
void WriteCsData(unsigned char cs);
//void delay(unsigned char dly);

#endif /* __SEG7_H__ */
