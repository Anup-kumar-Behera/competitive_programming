#include<bits/stdc++.h>
#include<cstring>
using namespace std;

void reverseString(string s)
{
	stack<char> str;
	int i = 0;
	int l = s.length();
	
	while(i < l)
	{
		str.push(s[i]);
		i++;
	}
	while(!str.empty())
	{
		char a = str.top();
		cout<<a;
		str.pop();
	}
}
int main()
{
	string s;
	cout<<"Enter a string:";
	cin>>s;
	
	cout<<endl<<"The reversed string is:\n";
	reverseString(s);
	
	return 0;
}
