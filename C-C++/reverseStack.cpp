#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st, int x){
	if(st.empty())
		st.push(x);
	else{
		int t = st.top();
		st.pop();
		insert_at_bottom(st, x);
		
		st.push(t);
	}
}

void reverse(stack<int> &st){
	if(!st.empty()){
		int t = st.top();
		st.pop();
		
		reverse(st);
		insert_at_bottom(st, t);
	}
}
int main(){
	stack<int> st;
	
	for(int i = 0; i < 10; i++)
		st.push(i+1);
	
	reverse(st);
	cout<<"stack after reversing: \n";
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
