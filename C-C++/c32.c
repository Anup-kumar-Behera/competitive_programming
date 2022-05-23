//	TRAVERSE A DOUBLE DIMENSIONAL ARRAY

#include<stdio.h>
main()
{
		int x[3][5]={10,20,30,40,50,
				 60,70,80,90,21,
				 99,32,45,67,89};
	printf("%d %d %d \n",x[1][3],*(*(x+1)+3),*(x[1]+3));
}
