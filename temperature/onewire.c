#include<REGX52.H>

sbit onewire_DQ=P3^7;
unsigned char onewire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	onewire_DQ=1;
	onewire_DQ=0;
	i=247;while (--i);  //delay 500us
	 onewire_DQ=1;
	i=32;while (--i); //delay 70us
	AckBit=onewire_DQ;
	i=247;while (--i);  //delay 500us
	return AckBit;
}
void onewire_SendBit(unsigned char Bit)
{
	unsigned char i;
	onewire_DQ=0;	
	i=4;while(--i);   //delay10us
	onewire_DQ=Bit;
	i=24;while(--i);	//delay 50us
	onewire_DQ=1;
}
unsigned char onewire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	onewire_DQ=0;
	i=2;while(--i);//delay5us
	onewire_DQ=1;
	i=2;while(--i);//delay5us
	Bit=onewire_DQ;
	i=24;while(--i);//delay50us
	return Bit;
	
}
void onewire_SendByte (unsigned char Byte)
{
	unsigned char i;
	for (i=0;i<8;i++)
	{
		onewire_SendBit(Byte&0x01<<i);
	}
}
unsigned char onewire_ReceiveByte (void)
{
	unsigned char i;
	unsigned char Byte=0x00;
	for (i=0;i<8;i++)
	{
		if (onewire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}
	



