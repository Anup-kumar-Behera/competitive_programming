#include"stdio.h"
main()
{
	int l=sizeof(int );
	int j=sizeof(int*);
	int k=sizeof(int**);
	
	printf("%d %d %d",l,j,k);
}
