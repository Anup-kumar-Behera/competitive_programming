//	REMOVE THE DUPLICATE ELEMENTS OF AN ARRAY
#include"stdio.h"
int remove_duplicates(int [],int );
main()
{
	int i,k;
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int x[n];
	printf("Enter the array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
	k=remove_duplicates(x,n);
	for(i=0;i<k;i++)
		printf("%d ",x[i]);
}
int remove_duplicates(int x[],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(x[i]==x[j])
			{
				k=j;
				n--;
				while(k<n)
				{
					x[k]=x[k+1];
					k++;
				}
				j=0;
			}
		}
	return n;
}
