#include<stdio.h>
main()
{
	int a[5]={27,68,21,90,2};
	int *p;
	p=a;
	int i,j,temp;
	for(i=0;i<5;i++)
	{
		printf("%d	",p[i]);
	}
	printf("\n");
	
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(p[i]>a[j])
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d	",p[i]);
	}
	
}
