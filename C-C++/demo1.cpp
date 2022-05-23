// C++ program to check if given array 
// has 2 elements whose sum is equal 
// to the given value 
#include <bits/stdc++.h> 

using namespace std; 

/* Driver program to test above function */
bool solve(vector<int> v, map<int, int> mp, int k){
	int c = 0;
	for(int i = 0; i < v.size(); i++){
		int t = k - v[0];
		if(mp.find(t) != mp.end())
			return true;
	}
	return false;
}
int main() 
{ 
	int n;
	cin>>n;
	vector<int> v;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int t;
		cin>>t;
		mp[t]++;
		v.push_back(t);
	}
	int c = 0;
	map<int, int>::iterator it;
	for(int i = 0; i < n; i++){
		int t = 2 * v[i];	
		it = mp.find(v[i]);
		mp.erase(it);
		if(solve(v, mp, t))
			c++;
		//v.push_back(t);
		mp[v[i]]++;
	}
	cout<<c<<endl;
	return 0; 
} 

