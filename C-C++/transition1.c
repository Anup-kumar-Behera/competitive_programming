#include<stdio.h>

main()
{	
	int n;
	
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int a[n];
	int i;
	for(i = 0;i < n;i++)
	{
		printf("Enter %d array element: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n");
	int l = 0,h = n-1,pos = 0;
	while(l < h)
	{
		int m = (l+h)/2;
		
		if(a[m-1] == 0 && a[m+1] == 1)
		{
			pos = m;
			break;
		}
		if(a[m] == 0 && a[m+1] != 1)
			l = m+1;
		else if(a[m] == 1 && a[m-1] != 0)
			h = m-1;
	}
	printf("Transition is : %d\n",pos);
}
