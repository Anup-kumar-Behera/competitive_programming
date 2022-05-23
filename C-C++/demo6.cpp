#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
void solve(string s, ll n){
	string p = "KICK";
	for(int i = 0; i < n; i++){
		int j = i+3;
		if(s[i] == 'K' && j < n){
			if(p.compare(s.substr(i, j)) == 0)
				cout<<s.substr(i, j)<<" : "<<i<<endl;
		}
	}
}
int main(){
    
    ll t;
    cin>>t;
    for(ll i = 0; i < t; i++){
       string s = "AKICKSTARTPROBLEMNAMEDKICKSTART";
       ll n = s.length();
       
       solve(s, n);
    }
    
    return 0;
}
