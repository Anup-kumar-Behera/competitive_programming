#include"stdio.h"
int eq(int [],int );
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter %d element: ",i+1);
		scanf("%d",&a[i]);
	}
	int e=eq(a,n);
	printf("The equilibrium point is: %d\n",e);
}
int eq(int a[],int n)
{
	int i=,j=0,k=0,s=0;
	int temp=0,k1=0,k2=0,s1=0,s2=0;
	
	while(j<n)
	{
		for(i=1;i<n;i++)
		{
			s1=s1+a[k];
			if(a[0]==s1)
				temp=1;
			else
		}
	
	}
	if(temp==0)
		return -1;
	else
		return temp;
}
