#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n;
	cin>>m;
	
	int l[m], r[m], id[m];
	
	for(int i = 0; i < m; i++)
		cin>>l[i];
		
	for(int i = 0; i < m; i++)
		cin>>r[i];
	
	for(int i = 0; i < m; i++)
		cin>>id[i];
	
	vector<vector<int> > arr;
	for(int i = 0; i < m; i++){
		vector<int> v;
		v.push_back(l[i]);
		v.push_back(r[i]);
		v.push_back(id[i]);
		
		arr.push_back(v);
	}
	
	
	return 0;
}

