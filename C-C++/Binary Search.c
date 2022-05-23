#include"stdio.h"
main()
{
	int a[10]={1,2,3,4,5,6,8,9,12,34};
	int n=10;
	int lb=1,ub=10;
	int mid=(lb+ub)/2;
	int item,loc;
	printf("Enter an item to search: ");
	scanf("%d",&item);
	while(lb<=ub && a[mid]!=item)
	{
		if(item<a[mid])
			ub=mid-1;
		else
			lb=mid+1;
		mid=(lb+ub)/2;
	}
	if(a[mid]==item)
		loc=mid;
	else
		loc=0;
	printf("%d\n",loc);
}
