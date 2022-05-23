#include<stdio.h>
int min(int ,int );
int fibSearch(int [],int ,int );

main()
{
	int x[]={10,22,35,40,45,50,80,82,85,90,100};
	int n=sizeof(x)/sizeof(x[0]);
	int key=85;
	printf("Found at index: %d\n",fibSearch(x,key,n));
}

int fibSearch(int x[],int k,int n)
{
	int fibMMm2=0;
	int fibMMm1=1;
	int fibM = fibMMm1+fibMMm2;
	while(fibM<n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm1+fibMMm2;
	}
	int offset=-1;
	while(fibM>1)
	{
		int i= min(offset+fibMMm2,n-1);
		
		if(x[i]<k)
		{
			fibM=fibMMm1;
			fibMMm1=fibMMm2;
			fibMMm2=fibM-fibMMm1;
			offset = i;
		}
		else if(x[i]>k)
		{
			fibM=fibMMm2;
			fibMMm1=fibMMm1-fibMMm2;
			fibMMm2=fibM-fibMMm1;
		}
		else return i;
	}
	if(fibMMm1 && x[offset+1]==x)
		return offset+1;
	return -1;
}
int min(int x,int y)
{
	if(x>y)
		return y;
	else
		return x;
}
