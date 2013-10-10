#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar receive_buf[101];
uchar buf_index=0;

//SEG
uchar code dis_code[]={0,9};

void delay(uint ms)
{
	uchar i;
	while(ms--)
		for(i=0;i<120;i++);
}

void main()
{
	uchar i;
	P0=0x00;
	receive_buf[0]=1;
	SCON=0X50; //串口模式1，允许接收
	TMOD=0x20; //T1工作模式2
	TH1=0xfd;  //波特率9600
	TL1=0xfd;
	PCON=0x00; //波特率不倍增
	EA=0;EX0=1;IT0=1;
	ES=1;IP=0X01;
	TR1=1;
	while(1)
	{
		for(i=0;i<100;i++)
		{
			if(receive_buf[i]==1) 
				break;
			 P1=dis_code[receive_buf[i]];
			 delay(200);
		}
		delay(200);
	}

}


//串口接收中断函数
void serial_int() interrupt 4
{
	uchar c;
	if(RI==0) 
		return;
	 ES=0;
	 RI=0;
	 c=SBUF;
	 if(c>='0'&&c<='9')
	 {
	 	receive_buf[buf_index]=c-'0';
		receive_buf[buf_index+1]=-1;
		buf_index=(buf_index+1)%100;
	 }
	 ES=1;
}

void EX_int0() interrupt 0
{
	uchar *s="这是发送的字符串\r\n";
	uchar i=0;
	while(s[i]!='\0')
	{
		SBUF=s[i];
		while(TI==0);
		TI=0;
		i++;
	}
}













