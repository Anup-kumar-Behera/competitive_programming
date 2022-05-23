#include<bits/stdc++.h>
using namespace std;

int prec(char c){
	switch(c){
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
		default: return -1;
	}
}
string ip(string s){
	stack<char> st;
	st.push('N');
	
	int n = s.length();
	
	string ans = "";
	for(int i = 0; i < n; i++){
		if((s[i]>= 'a' && s[i] <= 'z')||(s[i]>= 'A' && s[i] <= 'Z'))
			ans += s[i];
		else if(s[i] == '(')
			st.push(s[i]);
		else if(s[i] == ')'){
			while(st.top() != 'N' && st.top() != '('){
				char c = st.top();
				st.pop();
				ans += c;
			}
			if(st.top() == '('){
				//char c = st.top();
				st.pop();
			}
		}
		else{
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){
				char c = st.top();
				st.pop();
				ans += c;
			}
			st.push(s[i]);
		}
	}
	while(st.top() != 'N'){
		ans += st.top();
		st.pop();
	}
	return  ans;
}

int main(){
	
	string s;
	cout<<"Enter a string: ";
	cin>>s;
	
	cout<<ip(s)<<endl;
	
	return 0;
}
