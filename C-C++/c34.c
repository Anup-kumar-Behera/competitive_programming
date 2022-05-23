#include<stdio.h>
main()
{
	int a[5]={90,56,32,56,90};
	int l=a[0],i,m=a[0];
	for(i=1;i<=5;i++)
	{
		if(l<a[i] && l!=a[i])
			l=a[i];
	/*	if(m<l)
		{
			int temp=m;
			m=l;
			temp;
		}*/
	}
	for(i=1;i<=5;i++)
	{
		if(m<a[i] && m!=a[i])
			m=a[i];
	}
	printf("%d %d \n",l,m);
}
