#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[10];
	cout<<"Enter array elements: \n";
	for(int i = 0;i < 10;i++)
	{
		cout<<"Enter "<<i+1<<"array element: ";
		cin>>a[i];
	}
	queue<int> pq;
	for(int i = 0;i < 10;i++)	
		pq.push(a[i]);
	for(int i = 0;i<10;i++)
	{
		cout<<*(pq+i)<<endl;
	}
	//cout<<pq.pop()<<endl;
	return 0;
}
