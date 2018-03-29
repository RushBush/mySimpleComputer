#include "myReadkey.h"


int rk_readkey(enum keys *key)
{
	char buff[16];
	int char_read=read(1,buff,15);
	
	if (char_read<0)
		return -1;
	if (strncmp(buff,"l",1)==0)
		*key=KEY_l;
	if (strncmp(buff,"s",1)==0)
		*key=KEY_s;
	if (strncmp(buff,"r",1)==0)
		*key=KEY_r;
	if (strncmp(buff,"t",1)==0)
		*key=KEY_t;
	if (strncmp(buff,"i",1)==0)
		*key=KEY_i;
	if (strncmp(buff,"\E[15~",5)==0)
		*key=KEY_f5;
	if (strncmp(buff,"\E[17~",5)==0)
		*key=KEY_f6;
	if (strncmp(buff,"\E[A",3)==0)
		*key=KEY_up;
	if (strncmp(buff,"\E[B",3)==0)
		*key=KEY_down;
	if (strncmp(buff,"\E[D",3)==0)
		*key=KEY_left;
	if (strncmp(buff,"\E[C",3)==0)
		*key=KEY_right;
	if (strncmp(buff,"\n",1)==0)
		*key=KEY_enter;
		
	return 0;
}

int rk_mytermsave()
{
	struct termios opt;
	FILE *f;
	
	if (tcgetattr(STDIN_FILENO, &opt)!=0)
		return -1;
	if ((f=fopen("settings","wb"))==NULL)
		return -1;
		
	fwrite(&opt,sizeof(opt),1,f);
	fclose(f);
	
	return 0;
}

int rk_mytermrestore()
{
	struct termios opt;
	FILE *f;

	if ((f=fopen("settings","rb"))==NULL)
		return -1;
		
	if (fread(&opt,sizeof(opt),1,f)>0)
	{
		if (tcsetattr(STDIN_FILENO,TCSAFLUSH,&opt)!=0)
			return -1;
	}
	else
		return -1;

	return 0;
}

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
	struct termios opt;
	
	if (tcgetattr(STDIN_FILENO,&opt)!=0)
		return -1;
		
	if (regime==1)
		opt.c_lflag|=ICANON;
	else if (regime==0)
		opt.c_lflag&=~ICANON;
	else
		return -1;
		
	if (regime==0) 
	{
		opt.c_cc[VTIME]=vtime;
		opt.c_cc[VMIN]=vmin;
		
		if (echo==1)
			opt.c_lflag|=ECHO;
		else if (echo==0)
			opt.c_lflag&=~ECHO;
		else
			return -1;
			
		if (sigint==1)
			opt.c_lflag|=ISIG;
		else if (sigint==0)
			opt.c_lflag&=~ISIG;
		else
			return -1;
	}
	
	if (tcsetattr(STDIN_FILENO, TCSANOW, &opt)!=0)
		return -1;
	
	return 0;
}

