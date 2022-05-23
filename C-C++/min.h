#include<stdio.h>
int min(int [], int );

int min(int arr[],int n)
{
	int i,a=arr[0];
	for(i=0;i<n;i++)
	{
		if(a>arr[i])
			a=arr[i];
	}
	return a;
}
