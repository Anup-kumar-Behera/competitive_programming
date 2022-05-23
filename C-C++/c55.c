// 	INTERCHANGE TWO ALTERNATE ELEMENTSOF AN ARRAY

#include"stdio.h"
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	
	int x[n];
	int i,temp;
	printf("enter array elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	for(i=0;i<n;i=i+2)
	{
		temp=x[i];
		x[i]=x[i+1];
		x[i+1]=temp;
	}
	printf("\nArray elements after interchange: \n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
