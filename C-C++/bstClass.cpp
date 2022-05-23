#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	
	Node(int data){
		this->data = data;
		left = right = NULL;
	}

};
	
class BSTree{
	public:
	Node *root;
	BSTree(){
		root = NULL;
	}
	void insert(int data){
		if(!root){
			root = new Node(data);
			return;
		}
		Node *newnode = new Node(data);
	    Node* x = root;
	    Node* y = NULL;
//	 	if(!)
	    while (x != NULL) {
	        y = x;
	        if (data < x->data)
	            x = x->left;
	        else
	            x = x->right;
	    }
	    if (y == NULL)
	        y = newnode;
	    else if (data < y->data)
	        y->left = newnode;
	    else
	        y->right = newnode;
	 
	
//	    return y;
	}
	void search(int data){
		if(!root){
			cout<<"Tree is Empty!"<<endl;
			return;
		}
		
		stack<Node *> s;
		s.push(root);
		
		while(s.size()){
			Node *p = s.top();
			s.pop();
			
			if(p->data == data){
				cout<<"data "<<data<<" found"<<endl;
				return;
			}
			
			if(p->right)
				s.push(p->right);
			if(p->left)
				s.push(p->left);
		}
		cout<<"data "<<data<<" not found"<<endl;
	}
	void maxValue(){
		if(!root){
			cout<<"empty"<<endl;
			return;
		}
		int m = INT_MIN;
		
		Node *p = root, *q;
		
		while(p){
			q = p;
			p = p->right;
		}
		cout<<"Max Value: "<<q->data<<endl;
	}
	void depth(){
		int d = 0;
		if(!root){
			cout<<"Depth: "<<d<<endl;
			return;
		}
		
		queue<Node *> q;
		q.push(root);
		
		while(q.size()){
			int n = q.size();
			
			for(int i = 0; i < n; i++){
				Node *p = q.front();
				q.pop();
				
				if(p->left)
					q.push(p->left);
				if(p->right)
					q.push(p->right);
			}
			d++;
		}
		cout<<"Depth: "<<d<<endl;
	}
	void inorder(){
		stack<Node *> s;
		Node *curr = root;
		if(!root){
			cout<<"empty"<<endl;
			return;
		}
		cout<<"Inorder Traversal"<<endl;
		while(curr || !s.empty()){
			while(curr){
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			s.pop();
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		cout<<endl;
	}
	
};

int main(){
	BSTree t;
	t.insert(50);
	t.insert(30);
    t.insert(20);
    t.insert(40);
    t.insert(70);
    t.insert(60);
    t.insert(80);

	t.inorder();
	
	t.search(50);
	t.maxValue();
	t.depth();
}
