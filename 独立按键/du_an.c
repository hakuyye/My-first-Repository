#include<reg52.h>

typedef unsigned int u16;
typedef unsigned char u8;

void delay_10us(u8 n)
{

	unsigned char data i;

	while(n--)
	{
	i = 25;
	while (--i);
}

}

sbit KEY1 = P3^0;
sbit KEY2 = P3^1;
sbit KEY3 = P3^2;
sbit KEY4 = P3^3;

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;

#define KEY1_PASS 1
#define KEY2_PASS 2
#define KEY3_PASS 3
#define KEY4_PASS 4
#define KEY_UNPASS 0

u8 key_scan(u8 mode)
{
	static u8 key=1;
	//if(mode==1) key=1;
	if(key==1&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		delay_10us(1000);
		key=0;
			if(KEY1==0)
				return KEY1_PASS;
			else if(KEY2==0)
				return KEY2_PASS;
			else if(KEY3==0)
				return KEY3_PASS;
			else if(KEY4==0)
				return KEY4_PASS;
	
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)
	{
		if(mode==1) key=1;
//		if(mode==1)
//		{
//		key=1;
//		}
	
	}
		return KEY_UNPASS;

}

void main()
{
	u8 key=0;
	while(1)
	{
	key=key_scan(1);
		if(key==KEY1_PASS)
			LED1=!LED1;
		if(key==KEY2_PASS)
			LED2=!LED2;
		if(key==KEY3_PASS)
			LED3=!LED3;
		if(key==KEY4_PASS)
			LED4=!LED4;
		
	}

}