#include <bits/stdc++.h>
using namespace std;

int countWords(string b, vector<string> v){

}
int main(){
	int n, d;
	cin>>n>>d;
	
	int c = 0;
	map<vector<string>, int> mp;
	for(int i = 0; i < n; i++){
		string a, b;
		int t;
		cin>>a>>b>>t;
		
		vector<string> v;
		v.push_back(a);
		v.push_back(b);
		sort(v.begin(), v.end());
		
		if(mp.find(v) != mp.end()){
			mp[v];
			if(abs(t - mp[v]) <= d)
				c++;
		}else{
			mp[v] = t;
		}
	}
	cout<<c<<endl;
}
