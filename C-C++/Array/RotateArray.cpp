#include"iostream"
using namespace std;

//left rotate array by 1
void left_rotate1(int a[],int n)
{
	int temp=a[0],i;
	for(i=0;i<n-1;i++)
		a[i]=a[i+1];
	a[i]=temp;
}
void left_rotate(int a[],int d,int n)
{
	for(int i=0;i<d;i++)
		left_rotate1(a,n);
}
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	
	left_rotate(a,2,n);
	printArray(a,n);
	return 0;
}
