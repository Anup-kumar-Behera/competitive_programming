#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int r,int m)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	
	int L[n1],R[n2];
	
	for(i = 0;i < n1;i++)
		L[i] = arr[i+l];
	for(i = 0;i < n2;i++)
		R[i] = arr[m+l+i];
		
	i = 0;
	j = 0;
	k = l;
	
	while(i < n && j < n2)
	{
		if(L[])
	}
}
