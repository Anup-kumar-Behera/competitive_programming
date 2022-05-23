#include"stdio.h"
#include"min.h"
main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int i,x[n];
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter %d array element: ",i+1);
		scanf("%d",&x[i]);
	}
	printf("%d\n",min(x,n));
}
