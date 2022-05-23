#include<iostream>

using namespace std;

int getSum(int BITree[],int index)
{
	index = index+1;
	int sum = 0;
	
	while(index > 0)
	{
		sum += BITree[index];
		
		index -= index&(-index);
	}
	
	return sum;
}
void updateBIT(int BITree[],int n,int index,int val)
{
	index += 1;
	
	while(index <= n)
	{
		BITree[index] += val;
		
		index += index & (-index);
	}
}
int *constructBITree(int arr[],int n)
{
	int *BITree = new int[n+1];
	for(int i = 0; i < n;i++)
		BITree[i] = 0;
		
	int i;
	for(i = 0;i < n;i++)	
		updateBIT(BITree, n, i, arr[i]);
		
	return BITree;
}
int main()
{
	int arr[] = {2,1,1,3,2,3,4,5,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int *BITree = constructBITree(arr,n);
	cout<<"Sum of elements in arr is:"<<getSum(BITree,5);
	
	arr[3] += 6;
	updateBIT(BITree,n,3,6);
	
	cout<<"\nSum of updated first 5 elemets is:"<<getSum(BITree,5);
	
	return 0;
}
