#include <bits/stdc++.h>
using namespace std;

int countWords(string b, vector<string> v){
	int c = 0;
	for(int i = 0; i < v.size(); i++){
		if(b.length() <= v[i].length() && v[i].substr(0, b.length()) == b)
			c++;
	}
	return c;
}
int main(){
	int p;
	cin>>p;
	
	vector<string> v;
	for(int i = 0; i < p; i++){
		string a, b;
		cin>>a>>b;
		
		if(a == "add")
			v.push_back(b);
		else
			cout<<countWords(b, v)<<endl;
	}
}
