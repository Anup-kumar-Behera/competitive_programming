//DELETE AN ELEMENT AT ANY POSITION OF AN ARRAY

#include"stdio.h"
main()
{
	int x[5]={10,20,30,40,50};
	int pos,i;
	printf("Enter positon to delete: ");
	scanf("%d",&pos);
	
	for(i=pos;i<5;i++)
	{
		x[i]=x[i+1];
	}
	for(i=0;i<5;i++)
		printf("%d ",x[i]);
}
