
#include<INTRINS.H>
void delay(unsigned char xms)
{
	unsigned char  i, j;
	while(xms>0)
	{
		_nop_();
		i=2;
		j=199;
		do
		{
			while(--j);
		}while(--i);
		xms--;
	}
}