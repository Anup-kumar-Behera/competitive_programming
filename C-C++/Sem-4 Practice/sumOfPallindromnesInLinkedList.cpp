#include<bits/stdc++.h>
#include <cstring>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *newNode(int data){
	node *newNode = new node();
	newNode->data = data;
	newNode->next = 0;
	
	return newNode;
}

void *createList(node *head){
	
	int data, i = 2;
	char x[5];
	cout<<"1. Enter data: ";
	cin>>data;
	
	head = newNode(data);
	node *p = head;
	if(!head)
		return 0;
	else
	{
		while(1){
			
			cout<<endl<<"Do you want to continue (Y/N): ";
			cin>>x;
			
			if(strcmp(x,"N") == 0)
				break;
			cout<<endl<<i<<". Enter data: ";
			cin>>data;
			node *q = newNode(data);
			
			p->next = q;
			p = p->next;
			i++;
		}
		p->next = 0;
	}
}
void dsp(node *head){
	if(!head)
		cout<<endl<<"Underflow!\n";
	else{
		node *p = head;
		while(p != 0)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
	}
}
int main()
{
	int n;
	node *head;
	do{
		cout<<endl<<"Enter 1 to create list.\n";
		cout<<"Enter 2 to display list.\n";
		cout<<"Enter 3 to check pallindrome.\n";
		cout<<"Enter 0 to exit.\n";
		cout<<"Enter choice: ";
		cin>>n;
		
		if(n == 1){
			cout<<endl;
			createList(head);
			cout<<endl;
		}
		else if(n == 2){
			cout<<endl;
			dsp(head);
			cout<<endl;
		}
		else if(n == 3){
			
		}
	}while(n != 0);
	return 0;
}
