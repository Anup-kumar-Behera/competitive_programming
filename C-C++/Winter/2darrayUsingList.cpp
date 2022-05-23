#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *right, *down;
};

node *construct(int [][],int ,int ,int ,int );
void dsp(node *);

int main()
{
	int a,b;
	cout<<"Enter the array dimensions 'a' and 'b' : ";
	cin>>a>>b;
	int i,j,arr[a][b];
	cout<<"Enter array elements: \n";
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
		{
			cout<<"Enter arr[%d][%d] element: ",i+1,j+1;
			cin>>arr[i][j];
		}
	node *head = construct(arr, 0, 0, a, b);
	dsp(head);
	
	return 0;
}

node *construct(int arr[][],int i,int j,int m,int n)
{
	if(i > n-1 || j > m-1)
		return NULL;
		
	node *temp = new node();
	temp->data = arr[i][j];
	temp->right = construct(arr,i,j+1,m,n);
	temp->down  = construct(arr,i+1,j,m,n);
	return temp;
}

void dsp(node *head)
{
	node *rp,*dp = head;
	
	while(dp)
	{
		rp = dp;
		
		while(rp)
		{
			cout<<rp->data<<" ";
			rp = rp->right;
		}
		cout<<"\n";
		dp = dp->down;
	}
}
