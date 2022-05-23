#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() 
{ 
	int n;
	cin>>n;
   	vector<int> v, v1;
   	for(int i = 0; i < n; i++){
   		int t;
		cin>>t;
   		v.push_back(t);
	   }
	/*v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);*/
	int k;
	cin>>k;
	for(int i = 0; i < k; i++){
		int temp;
		cin>>temp;
		vector<int>::iterator p;
		p = v.begin();
		v1.push_back(*(p+temp-1));
		v.erase(p+temp-1);
		
	}
	vector<int>::iterator i;
	for(i = v1.begin(); i != v1.end(); i++)
		cout<<*i<<endl;
	
   	return 0;
} 

