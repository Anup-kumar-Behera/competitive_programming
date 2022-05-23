#include"stdio.h"

main()
{
	int a[10]={1,4,9,12,32,37,47,57,76,98};
	int item;
	int i=0,j=9;
	int loc,k;
	for(k=0;k<10;k++)	
		printf("%d ",a[k]);
	printf("\nEnter item to search: ");
	scanf("%d",&item);
	while(i<j)
	{
		int m=(i+j)/2;
		if(item>m)
			i=m+1;
		else
			j=m-1;
		if(item==m)
			loc=i;
		i++;
	}
	printf("%d ",a[loc]);
}
