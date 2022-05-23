#include<stdio.h>
main()
{
	int a[5]={46,98,23,87,21};
	int i,j,temp;
	for(i=0;i<5;i++)
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
		printf("%d ",a[i]);
	}
	printf("\nthe largest and 2nd largest integer in the array is :%d 	%d ",a[4],a[3]);
	
}
