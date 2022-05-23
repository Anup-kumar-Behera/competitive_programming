#include<bits/stdc++.h>
using namespace std;

void camelCase(vector<string>& words,string pattern)
{
	
}

int main()
{
	int n;
	cout<<"Enter no of words: ";
	cin>>n;
	string pattern;
	
	vector<string> s;
	string str;
	for(int i = 0;i < n;i++)
	{
		cout<<"Enter "<<i+1<<" word : ";
		cin>>str;
		s.push_back(str);
	}
	cout<<endl<<"Enter pattern: ";
	cin>>pattern;
	
	cout<<endl;
	
	cout<<"Vector elements:\n";
	for(string i = s.begin();i <= s.end(),i++)
		cout<< *i <<" ";
	
	camelCase(s,pattern);
}
