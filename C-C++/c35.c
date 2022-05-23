#include<stdio.h>
main()
{
	int a[6]={12,45,3,66,8,9};
	int l=a[0],m=a[0],i;
	for(i=1;i<=6;i++)
	{
		if(l<a[i])
			l=a[i];
		//if(m<a[i] && m!=l)
		//	m=a[i];
	}
	for(i=1;i<=6;i++)
	{
		if(m<a[i] && m!=a[i])
			m=a[i];
	}
	printf("%d %d\n",l,m);
}
