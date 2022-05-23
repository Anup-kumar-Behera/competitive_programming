#include<stdio.h>
main()
{
	int x[8]={12,45,32,11,5,89,90,2};
	int l=x[0],m=x[0],temp,i;
	for(i=1;i<8;i++)
	{
		if(l<x[i])
			l=x[i];
		if(m<l)
		{
			temp=m;
			m=l;
			l=temp;
		}
	}
	printf("%d \n",l);
}
