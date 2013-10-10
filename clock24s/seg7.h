/*
 *	Copyright (C) 2006, 华中科技大学电气与电子科技创新中心
 *	All Rights Reserved.
 *	
 *	文件名:		seg7.h
 *	文件描述:	8段数码管驱动头文件
 *			
 *	当前版本:	1.0
 *	作者:		SangWei(swkyer@gmail.com)
 *	完成日期:	2005年12月12日
 *	
*/
#ifndef __SEG7_H__
#define __SEG7_H__

//sbit key=P1^5;

/* 函数声明 */
void WriteSegData(unsigned char seg);
void WriteCsData(unsigned char cs);
//void delay(unsigned char dly);

#endif /* __SEG7_H__ */
