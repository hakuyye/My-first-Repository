#include<reg52.h>

typedef unsigned int u16;//??16bit?
typedef unsigned char u8;//??8bit?
#define SMG_A_DP_PORT P0//SMG—???A-DP?????

u8 gsmg_code[17] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f ,0x77,0x7c,0x39,0x5e,0x79,0x71};//??0-F//gsmg???g??????

void Delay100ms(u16 n)	//@11.0592MHz
{
	unsigned char data i, j, k;

	while(n--)
	{
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
}



void main()
{
	u16 i;
	SMG_A_DP_PORT=0x00;
	for(i=0;i<16;i++)
	{
	SMG_A_DP_PORT=gsmg_code[i];Delay100ms(1);
	}
	SMG_A_DP_PORT=0;
	while(1);
	
	
	
}