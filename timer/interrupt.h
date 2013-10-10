#ifndef _INTERRUPT_H
#define _INTERRUPT_H

void InitInterrupt();
void InitPriority(); /*		IP寄存器操作，设置优先级	*/
void InitSerial();	 /*		串行接口控制寄存器			*/
//void IniTimer();	 /*	   定时器/计数器方式选择		*/

void InitTimer();	 //定时器
void InitCounter();	 //计数器


#endif
