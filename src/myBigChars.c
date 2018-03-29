#include "myBigChars.h"

int numbers[17][2] = {{0x2424243C, 0x3C242424},	
  					  {0x18181818, 0x18181818},	
					  {0x2020203C, 0x3C04043C},	
					  {0x2020203C, 0x03C20203C},	
					  {0x3C242424, 0x20202020},	
					  {0x404043C, 0x03C20203C},	
					  {0x404043C, 0x3C24243C},	
					  {0x2020203C, 0x20202020},	
				   	  {0x3C24243C, 0x3C242424},	
					  {0x3C24243C, 0x3C202020},	
					  {0x24242418, 0x2424243C},	
					  {0x1C24241C, 0x1C24241C},	
					  {0x404043C, 0x3C040404},	
					  {0x2424241C, 0x1C242424},	
					  {0x3C04043C, 0x3C040404},	
					  {0x404043C, 0x404043C},		
					  {0x7E181800, 0x18187E}};

int bc_printA(char *str)
{
	printf("\E(0%s\E(B", str);
	return 0;
}


int bc_box(int x1, int y1, int x2, int y2)
{
	int tmp,max_x,max_y;
	
	if (x1 > x2) 
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	
	if (y1 > y2) 
	{
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	
	mt_getscreensize(&max_x, &max_y);
	
	if ((x1 < 0) || (y1 < 0) || (x2 > max_x) || (y2 > max_y) || (x2 - x1 < 2) || (y2 - y1 < 2))
		return -1;
		
	mt_gotoXY(x1, y1);
	
	bc_printA("l");
	
	for (int i=x1+1;i<x2;i++)
		bc_printA("q");
		
	bc_printA("k");
	
	for (int i=y1+1;i<y2;i++) 
	{
		mt_gotoXY(x1,i);
		bc_printA("x");
		mt_gotoXY(x2,i);
		bc_printA("x");
	}
	
	mt_gotoXY(x1, y2);
	
	bc_printA("m");
	
	for (int i=x1+1;i<x2;i++)
		bc_printA("q");
		
	bc_printA("j");
	
	return 0;
}

int bc_printbigchar(int *big, int x, int y, enum colors fg, enum colors bg)
{
	int max_x, max_y;
	int pos, bit;
	char row[9];
	
	mt_getscreensize(&max_x, &max_y);
	
	if ((x < 0) || (y < 0) || (x + 8 > max_x) || (y + 8 > max_y))
		return -1;
		
	row[8] = '\0';
	
	mt_setfgcolor(fg);
	mt_setbgcolor(bg);
	
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			pos = i >> 2;
			bit = (big[pos] >> ((i % 4) * 8 + j)) & 1;
			if (bit == 0)
				row[j] = ' ';
			else
				row[j] = 'a';
		}
		mt_gotoXY(x, y + i);
		bc_printA(row);
	}
	mt_setfgcolor(DEFAULT);
	mt_setbgcolor(DEFAULT);
	return 0;
}

int bc_printbigchar(int *big, int x, int y,colors fgcolor, colors bgcolor)
{
    mt_setfgcolor(fgcolor);
    mt_setbgcolor(bgcolor);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mt_gotoXY(x + i, y + j);
            int value;
            bc_getbigcharpos(big, j, i, &value);
            if (!value)
                write(1, " ", 1);
            else
                bc_printA((char*)BOXCHAR_REC);
        }
		mt_setbgcolor(DEFAULT);
		mt_setfgcolor(DAFAULT);
    }
    return 0;
}

int bc_setbigcharpos(int *big, int x, int y, int value)
{
    if (x < 0 || x > 7 || y < 0 || y > 7 || value > 1 || value < 1)
        return -1;
    int pos = (y > 3) ? 1 : 0;
    y %= 4;
    if (!value)
        big[pos] &= ~(1 << (y * 8 + x));
    if (value)
        big[pos] |= 1 << (y * 8 + x);
    return 0;
}

int bc_getbigcharpos(int *big, int x, int y, int *value)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
        return -1;
    int pos = y / 4;
    y %= 4;
    if (big[pos] & (1 << (y * 8 + x)))
        *value = 1;
    else
        *value = 0;
    return 0;
}

int bc_bigcharwrite(int fd, int *big, int count)
{
    for (int i = 0; i < count * 2; i++)
    {
        if (write(fd, &big[i], sizeof(int)) == -1)
        {
            return -1;
        }
    }
    return 0;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count)
{
    for (*count = 0; (*count < need_count * 2); *count += 1)
    {
        if (read(fd, &big[*count], sizeof(int)) == -1)
        {
            return -1;
        }
    }
    return 0;
}

void ToBigChar(int num,int *big)
{
	big[0]=numbers[num][0];
	big[1]=numbers[num][1];
}
