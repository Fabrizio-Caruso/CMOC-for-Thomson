#define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val)    (*(unsigned*) (addr) = (val))
#define PEEK(addr)         (*(unsigned char*) (addr))
#define PEEKW(addr)        (*(unsigned*) (addr))

#define VIDEO_ADDR 0x0000

void SWITCH_COLOR_BANK_ON(void);
void SWITCH_COLOR_BANK_OFF(void);

void PUTCH(unsigned char ch);

void CURSOR_BLINK_OFF(void);

void PRINT(char * str);

void gotoxy(unsigned char xx, unsigned char yy);

unsigned char GETCH(void);

#if defined(__MO6__)
	void palette(unsigned char pen, unsigned char red, unsigned char green, unsigned char blue)
#endif


