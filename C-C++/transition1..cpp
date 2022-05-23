#include<stdio.h>

main()
{
	int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1};
	
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	int l = 0,h = n-1,pos = 0;
	while(l < h)
	{
		int mid = (l+h)/2;
		
		if(a[m-1] == 0 and a[m+1] == 1)
		{
			pos = m;
			break;
		}
		if(a[m] == 0 and a[m+1] != 1)
			l = m+1;
		else if(a[m] == 1 and a[m-1] != 0)
			h = m-1;
	}
	printf("Transition is : %d\n",pos);
}
