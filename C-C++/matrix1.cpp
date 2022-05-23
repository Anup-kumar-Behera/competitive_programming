#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m,n,o,p;
	cout<<"Enter dimensions of the 1st matrix: ";
	cin>>m>>n;
	int arr[m][n];
	
	cout<<"Enter dimensions of the 2nd matrix: ";
	cin>>o>>p;
	int brr[o][p];
	
	int i,j,k;
	cout<<"Enter 1st matrix elements: \n";
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			cout<<"Enter arr["<<i+1<<"]["<<j+1<<"] element: ";
			cin>>arr[i][j];
		}
	}
		
	cout<<"\nEnter 2nd matrix elements: \n";
	for(i = 0;i < o;i++)
		for(j = 0;j < p;j++)
		{
			cout<<"Enter brr["<<i+1<<"]["<<j+1<<"] element: ";
			cin>>brr[i][j];
		}
		
	cout<<"\nMatrix 1 is :\n";
	for(i = 0;i < m;i++)
	{
		cout<<" \n";
		for(j = 0;j < n;j++)
		{
			cout<<arr[i][j]<<" \t";
		}
	}
	cout<<"\nMatrix 2 is :\n";
	for(i = 0;i < o;i++)
	{
		cout<<" \n";
		for(j = 0;j < p;j++)
		{
			cout<<brr[i][j]<<" \t";
		}
	}
	
	int c[m][p];
	if(n != o)
		cout<<"Matrix multiplication is not possible.\n";
	else
	{
		for(i = 0;i < m;i++)
		{
			for(j = 0;j < p;j++)
			{
					c[i][j] = 0;
				for(k = 0;k < n;k++)
				{
					c[i][j] += arr[i][k]*brr[k][j];
				}
			}
		}
		
		cout<<"\nThe resultant matrix is: \n";
		for(i = 0;i < m;i++)
		{
			cout<<" \n";
			for(j = 0;j < p;j++)
			{
				cout<<c[i][j]<<" \t";
			}
		}
	}
	
	return 0;
}
