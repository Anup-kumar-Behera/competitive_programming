#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, q, m;
		cin>>n>>q>>m;
		
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		int b[1000001] = {};
		
		int ans[n+1] = {};
		
		map<pair<int, int> , int> mp;
		
		while(q--){
			int l, r;
			cin>>l>>r;
			l--, r--;
			if(a[l] > m)
				continue;
			
			else if(a[l] <= m && a[r] > m){
				b[a[l]]++, b[m+1] --;
			}
			
			else if(a[r] <= m){
				b[a[l]]++, b[m+1]--;
				mp[{a[l], a[r]}]++;
			}
		
		}
		for(auto x: mp){
			int a = x.first.first, p = x.first.second, li = x.second;
			
			b[p+a] -= li, b[p+2*a] += li;
			int c = p + 2*a;
			
			while(c + a <= m){
				c += p;
				b[c] -= li, b[c+a] += li;
				c += a;
			}
	
		}
		int mx = 0;
		for(int i = 1; i <= m; i++){
			b[i] += b[i-1];
			mx = max(mx, b[i]);
		}
		cout<<mx<<endl;
	
	}
}
