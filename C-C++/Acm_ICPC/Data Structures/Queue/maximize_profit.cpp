#include<bits/stdc++.H>

using namespace std;


int maximize_profit(int a[],int n,int m)
{
	priority_queue<int> pq;
	int i;
	for (i = 0;i<n;i++ )
		pq.push(a[i]);
	
	int profit = 0, c = 0;
	while(c < m)
	{
		int top = pq.top();
		
		pq.pop();
		
		if (top == 0)
			break;
			
		profit = profit+top;
		
		pq.push(top-1);
		
		c++;
		
	}
		return profit;
}
int main()
{
	int a[] = {2,3,4,5,1};
	int profit = maximize_profit(a,5,6);
	cout<<profit<<endl;
	return 0;
}
