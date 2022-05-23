#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		unordered_set<string> s1, s2;
		set<char> sc1, sc2;
		
		unordered_set<string>::iterator it1 , it2;
		set<char>::iterator itc;
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			
			sc1.insert(s[0]);
			s1.insert(s);
		}
		
		for(it1 = s1.begin(); it1 != s1.end(); it1++){
			for(itc = sc1.begin(); itc != sc1.end(); itc++){
				string tt = *it1;
				if(*itc != tt[0]){
					string temp = "";

					temp += tt;
					temp[0] = *itc;
					if(s1.find(temp) == s1.end()){
						s2.insert(temp);
					}
				}
			}
		}
		
		int ans = 0;
		for(it1 = s2.begin(); it1 != s2.end(); it1++){
			for(it2 = s2.begin(); it2 != s2.end(); it2++){
				if(*it1 != *it2){
					string a = *it1, b = *it2, t1 = "" ,t2 = "";
					char c1 = a[0], c2 = b[0];
					t1 += a, t2 += b;
					t1[0] = c2, t2[0] = c1;
					
					if(s1.find(t1) != s1.end() && s1.find(t2) != s1.end()){
						ans++;
					//	s1.erase(a);
					}
				}
			}
		} 

		//cout<<sp.size()<<endl;
		cout<<ans<<endl;
	}
}
