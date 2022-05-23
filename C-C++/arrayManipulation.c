#include<stdio.h>


long arrayManipulation(int n, int r, int c, int queries[][c]) {
    long int arr[n];
    int i,j = 1,k,p = 0;
    long max;
    long int m[r];
    for(i = 0;i < r;i++)
        m[i] = 0;

    for(i = 0; i < n;i++)   
        arr[i] = 0;
    for(i = 0;i < r;i++)
    {
        for(k = queries[i][j-1];k <= queries[i][j];k++)
        {
            arr[k] = arr[k]+queries[i][j+1];
        }
    }
    max = arr[0];
    for(i = 0;i < n;i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;

}
main()
{
	int n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int m;
	printf("Enter row size : ");
	scanf("%d",&m);
	
	int k = 3;
	int a[m][k];
	int i,j;
	printf("Enter values of a,b and k : \n");
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < 3;j++)
		{
			printf("Enter arr[%d][%d] value : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	long max = arrayManipulation(n,m,k,a);
	
	printf("max value is: %ld\n",max);
}
