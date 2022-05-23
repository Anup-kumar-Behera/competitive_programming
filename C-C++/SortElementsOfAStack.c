#include"stdio.h"
main()
{
	int x[5]={10,4,90,11,13};
	int y[5];
	int i=4,j=-1,temp;
	while(i>=0)
	{
		temp=x[i];
		i--;
		if(j==-1)
		{
			j++;
			y[j]=temp;
		}
		else
		{
			if(temp<y[j])
			{
				j++;
				y[j]=temp;
			}
			else
			{
				while(j>=0 && temp>=y[j])
				{
					i++;
					x[i]=y[j];
					j--;
				}
				j++;
				y[j]=temp;
			}
		}
	}
	while(j>=4)
	{
		printf("%d \n",y[j]);
		j--;
	}
}
