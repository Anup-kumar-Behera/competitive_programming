#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *right,*down;
};
node *newNode(int d)
{
	node *temp = new node;
	temp->data = d;
	temp->right = temp->down = 0;
	return temp;
}
void display(node *head)
{
	node *rp, *dp = head;
	
	while(dp)
	{
		rp = dp;
		
		while(rp)
		{
			cout<<rp->data<<" ";
			rp = rp->right;
		}
		cout << endl;
		dp = dp->down;
	}
}
node *createLinkedMatrix(int mat[][],int m,int n)
{
	node *mainhead = NULL;
	
	node *head[m];
	node *righttemp,*newptr;
	int i,j;
	for(i = 0;i<m;i++)
	{
		head[i] = NULL;
		for(j = 0; j < n; j++)
		{
			newptr = newNode(mat[i][j]);
			
			if(!mainhead)	
				mainhead = newptr;
			if(!head[i])
				head[i] = newptr;
			else
				righttemp->right = newptr;
			righttemp = newptr;
		}
	}
	
	for(i = 0; i < m-1; i++)
	{
		node *temp1 = head[i], *temp2 = head[i+1];
		while(temp1 && temp2)
		{
			temp1->down = temp2;
			temp1 = temp1->right;
			temp2 = temp2->right;
		}
	}
	return mainhead;
 }

int main()
{
	
	int m,n;
	cout<< "Enter matrix dimensions: ";
	cin>>m>>n;
	
	int mat[m][n];
	int i,j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<"Enter mat[%d][%d] value: ",i+1,j+1;
			cin>>mat[i][j];
		}
	}
	node* head = createLinkedMatrix( mat, m, n);
	display(head);
	
	return 0;
}
