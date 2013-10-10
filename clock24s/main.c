#include"reg51.h"
#include"seg7.h"
#include <INTRINS.H>


sbit beep1=P1^4;
sbit pluse=P1^7;


unsigned char cs=0;			 //全局变量cs，位选
unsigned char dispram[4];



void delay(unsigned char dly);		  //延时函数
void beep();				//蜂鸣器
void display();    			//显示函数
void break1();				//暂停函数



//主函数
int main(void)
{

 	 int clk=0 ;
	 int min,sec;		   //定义分、秒

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
		clk++;				   //分频
		sec=clk/200;
		min=sec/10;

		if(min==2)
		{
			if(sec%10==4)
		   {	beep();
			dispram[0]=4;
			dispram[1]=2; }
		}

		//显示	
		dispram[0] = sec%10;
		dispram[1] = min%10;
		dispram[2]=0;
		dispram[3]=0;
		display();


			//暂停
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

//延时函数
void delay(unsigned char dly)
{
	unsigned char i, j;

	for(i=100; i>0; i--)
		for(j=dly; j>0; j--);
}

//蜂鸣器
void beep()
{
	beep1=1;
	while(1)
	{
		beep1=~beep1;
		delay(1);
	}
}

// 数码管显示
 void display()
{
		if(cs >= 3)
			cs = 0;
    	else
			cs++;
    
		WriteSegData(dispram[cs]);	  //段选 写数据
    	WriteCsData(1<<cs);	          //位选  写数据

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




