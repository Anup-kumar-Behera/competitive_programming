#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}node;
node *head, *p, *prev;

void push(int data){
	if(!head){
        		head = (struct node *)malloc(sizeof(node));
        		if(!head)
        			cout<<"Overflow"<<endl;
        		p = head;
        		p->data = data;
        		p->next = NULL;
			}else{
			
			
				node *q = (struct node *)malloc(sizeof(node));
				if(!q)
					cout<<"Error"<<endl;
				q->data = data;
				q->next = NULL;
				prev = q;
				p->next = q;
				p = p->next;
			}
}
void pop(){	
	if(head == 0){
		cout<<"Underflow"<<endl;
		return;
	}
	int k = head->data;
	head = head->next;
	cout<<"popped item: "<<k<<endl;
}
void printStack(){
	if(!head)
	{
		cout<<"Underflow"<<endl;
		return ;
	}
	node *ptr = head;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}
int main(){
	int c;
	
	do{
		cout<<"\n1 to push"<<endl;
        cout<<"2 to pop"<<endl;
        cout<<"3 to print stack"<<endl;
//        cout<<"4 to print size of stack"<<endl;
        cout<<"Enter 0 to quit"<<endl;
        cout<<"Enter choice: ";
        cin>>c;
        
        if(c == 1){
        	int data;
            cout<<"Enter data to push: ";
            cin>>data;
        	push(data);
			
        }
        else if(c == 2){
            pop();
            
        }
        else if(c == 3){
            printStack();
        }
        else{
            cout<<"Invalid Choice!"<<endl;
        }
	}while(c != 0);
}

