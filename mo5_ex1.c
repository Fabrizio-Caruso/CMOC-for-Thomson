#include "mo5_lib.h"

int main()
{
	unsigned char ch;
	unsigned char i = 0;
	
	CURSOR_BLINK_OFF();
	
	gotoxy(10,10);
	PRINT("HELLO");

	gotoxy(10,12);
	while(i<10)
	{
		ch=GETCH();
		if(ch>0)
		{
			PUTCH(ch);
			++i;
		}
	}
	
	gotoxy(10,20);
	PRINT("END");

	while(1){};

	return 0;
}
