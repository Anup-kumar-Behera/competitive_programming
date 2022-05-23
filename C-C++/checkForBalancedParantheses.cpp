#include<bits/stdc++.h>
using namespace std;

void solve(string s){
	int n = s.length();
	
	stack<char> st;
	st.push(s[0]);
	for(int i = 1; i < n; i++){
		if(!st.empty()){
			if((s[i] == '(' && st.top() == ')') ||(s[i] == ')' && st.top() == '('))
				st.pop();
			else if((s[i] == '[' && st.top() == ']') || (s[i] == ']' && st.top() == '['))
				st.pop();
			else if((s[i] == '{' && st.top() == '}') || (s[i] == '}' && st.top() == '{'))
				st.pop();
			else
				st.push(s[i]);
		}
		else
			st.push(s[i]);
	}
	if(st.empty()){
		cout<<"Balanced\n";
		return;
	}
	cout<<"Not Balanced\n";
}
int main(){
	string s = "[(])";
	solve(s);
}
