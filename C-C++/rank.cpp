#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> v, int k){
    int c = 0;
    int n = v.size();
    for(int i = 0; i < n; i++)
        if(v[i] >= k)
            c++;
    return c;
}
int main() 
{ 
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0; i < n; i++){
	    int t;
	    cin>>t;
	    v.push_back(t);
	    cout<<solve(v, t)<<endl;
	}
	

	return 0; 
} 

