#include<stdio.h>
main()
{
	int a[5]={34,2,50,45,21};
	int i,j,s,temp;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]<a[j])
			{	
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d  \n",a[i]);
	}
}
