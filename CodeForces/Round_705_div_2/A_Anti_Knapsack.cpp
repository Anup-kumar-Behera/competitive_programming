#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	for(int i = 0; i < t; i++){
		int n, k;
		cin>>n>>k;
		vector<int> v;
		for(int j = k-1; j > k/2; j--){
			v.push_back(j); 
		}
		for(int j = k+1; j <= n; j++){
			v.push_back(j);
		}
		
		cout<<v.size()<<endl;
		for(int j = 0; j < v.size(); j++)
			cout<<v[j]<<" ";
		cout<<endl;
	}
	
}
