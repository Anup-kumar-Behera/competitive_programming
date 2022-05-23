#include<stdio.h>
int min([]);

int min(arr[])
{
	int i,a=arr[0];
	for(i=0;i<a;i++)
	{
		if(a<arr[i])
			a=arr[i];
	}
	return a;
}
