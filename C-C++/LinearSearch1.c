#include"stdio.h"
void linear(int [],int,int);

main()
{
	int n;
	printf("Enter the size of the array :");
	scanf("%d",&n);
	int i,a[n];
	printf("Enter the array elements : \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d element : ",i+1);
		scanf("%d",&a[i]);
	}
	int item,loc;
	printf("\nEnter the item to be searched : ");
	scanf("%d",&item);
	linear(a,n,item);
	
}
void linear(int a[],int n,int item)
{
	int l;
	a[n]=item;
	l=0;
	while(a[l]!=item)
		l=l+1;
	if(l==n)
		l=-1;
	if(l==-1)
		printf("\nItem is not present in a[%d] .\n",n);
	else
		printf("\nThe location of item in a[%d] is %d .\n",n,l);
}
