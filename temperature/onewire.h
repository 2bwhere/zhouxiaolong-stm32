#ifndef _ONEWIRE_H_
#define _ONEWIRE_H_
unsigned char onewire_Init(void);
void onewire_SendBit(unsigned char Bit);
unsigned char onewire_ReceiveBit(void);
void onewire_SendByte (unsigned char Byte);
unsigned char onewire_ReceiveByte (void);
#endif