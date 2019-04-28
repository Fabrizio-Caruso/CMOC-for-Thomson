#define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val)    (*(unsigned*) (addr) = (val))
#define PEEK(addr)         (*(unsigned char*) (addr))
#define PEEKW(addr) (*(unsigned*) (addr))

#define VIDEO_ADDR 0x0000

#if defined(__MO6__)
	#define COLOR_VALUE 0xA7DA
	#define PEN_INDEX   0cA7DB
#endif

void SWITCH_COLOR_BANK_ON(void)
{
	asm
	{
		swi
		.byte 4
	}	
}

void SWITCH_COLOR_BANK_OFF(void)
{
	asm
	{
		swi
		.byte 6
	}	
}	

void PUTCH(unsigned char ch)
{
	POKE(0x201B,0);
	asm
	{
		ldb ch
		swi
		.byte 2
	}
}


void CURSOR_BLINK_OFF(void)
{
	PUTCH(0x14);
}

void PRINT(char * str)
{
	unsigned char i = 0;
	
	while(str[i]!='\0')
	{
		PUTCH(str[i]);
		++i;
	}
}


void gotoxy(unsigned char xx, unsigned char yy)
{
	PUTCH(0x1F);
	PUTCH(0x40+yy);
	PUTCH(0x41+xx);
}	

unsigned char GETCH(void)
{
	unsigned char res;
	asm
	{
		swi
		.byte 10
		stb res
	}
	return res;	
}

#if defined(__MO6__)
void palette(unsigned char pen, unsigned char red, unsigned char green, unsigned char blue)
{
	POKE(PEN_INDEX,pen<<1);
	POKE(COLOR_VALUE,(green<<4)+blue);
	POKE(COLOR_VALUE,red);
}
#endif 
