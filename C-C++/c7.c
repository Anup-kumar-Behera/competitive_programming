#include<stdio.h>
main()
{
	int a[5]={12,34,56,21,32};
	int *p;
	p=a;
	printf("%u	%u	%u	%d\n",a,p,&a,sizeof(a));
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d	",a[i]);
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d 	",*(p+i));
	}
	printf("\n");
	int j,temp;
/*	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d	",a[i]);
	}*/
	printf("\n");
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(*(p+i)>*(p+j))
			{
				temp=*(p+j);
				*(p+j)=*(p+i);
				*(p+i)=temp;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d	",*(p+i));
	}
}
