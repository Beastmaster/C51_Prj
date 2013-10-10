/*
 *	Copyright (C) 2006, 华中科技大学电气与电子科技创新中心
 *	All Rights Reserved.
 *	
 *	文件名:		seg7.c
 *	文件描述:	8段数码管驱动主程序文件
 *			
 *	当前版本:	1.0
 *	作者:		SangWei(swkyer@gmail.com)
 *	完成日期:	2005年12月12日
 *	
*/
#include <reg51.h>
#include <INTRINS.H>
#include "..\key1\main.h"


/* 段码表 */
unsigned char code seg_code[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,	// 0--9
								 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};	// A, b, C, d, E, F, 消隐


/**************************************
说明:	写段码数据
seg:	待显示的段码数据, 0-9, A-F
**************************************/
void WriteSegData(unsigned char seg)
{
	/* 越界判断，并查找对应的段码 */
	if(seg > 16)
		seg = 16;
	seg = seg_code[seg];
	/* 将段码数据送到数据总线上 */
	P0 = seg;
	/* 等待数据稳定 */
	_nop_();
	_nop_();

	P2 &= 0x1F;	/* P2.5-P2.7 = 000, 控制138译码器，使片选信号CS0=0 */

	/* 延时，维持CS0为低电平 */
	_nop_();
	_nop_();


	P2 |= 0xE0;	/* P2.5-P2.7 = 111, CS0=1, 产生上升延脉冲，将数据总线上的数据锁存 */
}

/**************************************
说明:	写位选数据
cs:		cs低四位为位选位，1: 有效，0: 无效
**************************************/
void WriteCsData(unsigned char cs)
{

	cs &= 0x0F;	/* 低四位有效，屏蔽高四位 */	

	P0 = ~cs;  /* cs信号为低有效，将cs反向后送入数据总线 */

	/* 等待数据稳定 */
	_nop_();
	_nop_();

	/* P2.5 = 0, P2.6-P2.7 = 0, 控制138译码器，使片选信号CS1 = 0 */
	P2 &= 0x3F;
	/* 延时，维持CS1为低电平 */
	_nop_();
	_nop_();
	/* P2.5-P2.7 = 111, CS0=1, 产生上升延脉冲，将数据总线上的数据锁存 */
	P2 |= 0xE0;
}
