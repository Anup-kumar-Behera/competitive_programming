#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *head = 0, *p = 0, *top = 0;

void push(int data){
	if(head == 0){
		head = (node *)malloc(sizeof(node));
		p = head;
		p->data = data;
		p->next = 0;
		top = p;
	}
	else{
		node *q = (node *)malloc(sizeof(node));
		q->data = data;
		q->next = 0;
		p->next = q;
		p = p->next;
		top = p;
	}
}
int pop(){
	node *temp = head, *save;
	int k = top->data;
	
	while(temp->next){
		save = temp;
		temp = temp->next;
	}
	save->next = 0;
	top = save;
	free(temp);
	
	return k;
}
void dsp(){
	if(head == 0)
		cout<<"Underflow!\n";
	else{
		node *p = head;
		while(p != 0){
			cout<<p->data<<endl;
			p = p->next;
		}
	}
}

int main(){
	
	int n,data;
	do{
		cout<<"\nEnter 1 to push data:\n";
		cout<<"Enter 2 to pop data\n";
		cout<<"Enter 3 to display stack!\n";
		cout<<"Enter 0 to stop\n"	;
		cout<<"Enter choice: ";
		cin>>n;
		
		if(n == 1){
			cout<<"Enter data: ";
			cin>>data;
			push(data);
		}
		else if(n == 2){
			int k = pop();
			cout<<k<<endl;
		}
		else if(n == 3){
			dsp();
		}
	}while(n != 0);
	
	return 0;
}
