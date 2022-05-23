#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node *getNewNode(int data)
{
	node *newNode = new node();
	newNode->data = data;
	newNode->left = newNode->right = 0;
	
	return newNode;
}

node* insert(node *root,int data)
{
	if(root == 0)
	{
		root = getNewNode(data);	
	}
	else{
		if(data >= root->data)
			root->right = getNewNode(data);
		else if(data <= root->data)
			root->left  = getNewNode(data);
	}
	return root;
}

bool Search(node *root,int data)
{
	if(root == 0) return false;
	else if(root->data == data)
		return true;
	else if(data <= root->data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}

void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

int main()
{
	int n;
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	int arr[n];
	node *root = NULL;

	cout<<endl<<"Enter node values:\n";
	for(int i = 0;i < n;i++)
	{
		cout<<"Enter "<<i+1<<" node value: ";
		cin>>arr[i];
	}
	
	for(int i = 0;i < n;i++)
		root = insert(root,arr[i]);
	
	cout<<endl;
	inorder(root);
	
	int data;
	cout<<endl<<"Enter number to be searched: ";
	cin>>data;
	
	if(Search(root,data) == true)
		cout<<endl<<"Found\n";
	else
		cout<<endl<<"Not Found\n";
	
	return 0;
}
