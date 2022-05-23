#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int arr[20];
	int i;
	memset(arr,2,sizeof(arr));
	
	for(i = 0;i<sizeof(arr);i++)
		printf(" %d",arr[i]);
	
	return 0;
}
