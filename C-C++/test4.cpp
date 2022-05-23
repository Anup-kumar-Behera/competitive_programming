#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		unordered_set<string> s1, s2;
		
		unordered_set<string>::iterator it1 , it2;
		unordered_map<string, int>mp;
	
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			
			s1.insert(s);
			s2.insert(s);
			mp[s]++;
		}
		
		int ans = 0;
		for(it1 = s1.begin(); it1 != s1.end(); it1++){
			string a = *it1;
			s2.erase(*it1);
			for(it2 = s2.begin(); it2 != s2.end(); it2++){
				if(a[0] == b[0]){
					continue;
				}
				//string b = *it2;
				else{
					string b = *it2;
					char c = a[0];
					char d = b[0];
					string t1 = "", t2 = "";
					t1 += a, t2 += b;
					t1[0] = d, t2[0] = c;
					
//					if(s1.find(t1) == s1.end() && s1.find(t2) == s1.end()){
					if(mp.find(t1) == mp.end() && mp.find(t2) == mp.end()){
						ans++;
						
					}
				}
			}
		}
		
		cout<<ans*2<<endl;
		

		//cout<<sp.size()<<endl;
		//cout<<ans<<endl;
	}
}
