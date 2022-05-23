#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v){
	if(v.size() == 1)
		return 1;
	sort(v.begin(), v.end());
	
	int c = 0;
	vector<int> ind;
	ind.push_back(0);
	
	for(int i = 1; i < v.size(); i++){
		if(v[i] - v[i-1] != 1){
			ind.push_back(i);
		}
	}
	int ans = INT_MIN;
	
	for(int i = 1; i < ind.size(); i++)
		ans = max(ind[i] - ind[i-1], ans);
	return ans;
}
int main(){
	int n;
	cin>>n;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	
	cout<<solve(v)<<endl;
}
