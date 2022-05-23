// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<char, int> &a, 
              const pair<char, int> &b) 
{ 
    return (a.second < b.second); 
} 
typedef long long int ll;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n, e, h, a, b, c;
	    cin>>n>>e>>h>>a>>b>>c;
	    
	    vector<ll> ans, v;
       	for(int i = 0; i <= n+1; i++)    
       	    v.push_back(i);
       	
       	for(ll i = 0 ; i <= n; i++){
       	    ll id1 = lower_bound(v.begin(), v.end(), (2 * n - e - 2 * i)) - v.begin();
       	    ll id2 = upper_bound(v.begin(), v.end(), (h - 3 * i)) - v.begin() - 1;
       	    
       	    if(id2 < id1 || id1==n+1) continue;
       	    if(id2 == n+1 && id2+3*i > h) continue;
       	    
       	    ll k;
       	    if(c > a) 
       	        k = (id1 < (n-i) ? id1: (n-i));
       	    else
       	        k = (id2 < (n-i)? id2: (n-i));
       	    
       	    ll o = n-k-i;
       	    if(k + 2 * i >= 2 * n - e && k + 3 * i <= h)
       	        ans.push_back(a*o+b*i+c*k);
       	}
       	if(ans.size() == 0)
       	    cout<<-1<<endl;
       	else{
       	    ll m = ans[0];
       	    for(ll i = 0; i < ans.size(); i++)
       	        if(ans[i] < m)
       	            m = ans[i];
       	        
       	    cout<<m<<endl;
       	    
       	}
	}
	return 0;
}

