#include<REGX52.H >
#include"onewire.h"
#define DS18B20_SKIP_ROM 				0XCC
#define DS18B20_CONVERT_T 			0X44
#define DS18B20_READ_SCRATCHPAD 0XBE
void DS18B20_ConvertT(void)
{
	onewire_Init();
	onewire_SendByte(DS18B20_SKIP_ROM);
	onewire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT(void)
{
  unsigned char TLSB,TMSB;
	int temp;
	float t;
	onewire_Init();
	onewire_SendByte(DS18B20_SKIP_ROM);
	onewire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=onewire_ReceiveByte();
	TMSB=onewire_ReceiveByte();
	temp=(TMSB<<8)|TLSB;
	t=temp/16.0;
	return t;
}