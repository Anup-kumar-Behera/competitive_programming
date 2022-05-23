#include<stdio.h>
main()
{
	unsigned char ch;
	for(ch=0;ch<=255;ch++)
	{
		printf("%d %c \n",ch,ch);
		sleep(1);
	}
}
