#include"stdio.h"
main()
{
	int a[5]={64,25,12,22,11};
	int n=5;
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i;
		while(a[j-1]>temp && j>=1)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
