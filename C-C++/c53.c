#include"stdio.h"
main()
{
	int x[7]={0,1,2,3,5,6,9};
	int i,j,s=9;
	for(i=1;i<=7;i++)
	{
		for(j=1;j<=7;j++)
		{
			if(x[i]+x[j]==s)
				printf("(%d,%d)\t",x[i],x[j]);
		}
	}
}
