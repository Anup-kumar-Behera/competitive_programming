#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		unordered_set<string> s1, s2, s3, s4;
		unordered_set<char> ch;
		unordered_set<string>::iterator i2, i3;
		unordered_set<char>::iterator i1;
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			
			s1.insert(s);
			string temp = "";
			temp += s.substr(1, s.length() - 1);
			s2.insert(temp);
			ch.insert(s[0]);
		}
		
		for(i1 = ch.begin(); i1 != ch.end(); i1++){
			char c = *i1;
			for(i2 = s2.begin(); i2 != s2.end(); i2++){
				string t2 = "", a = *i2;
				t2 += c;
				t2 += a;
				
				if(s1.find(t2) == s1.end()){
	
					s3.insert(t2);
					s4.insert(t2);
				}
			}
		}
		
		
		int ans = 0;
		for(i2 = s3.begin(); i2 != s3.end(); i2++){
			string a = *i2;
			s4.erase(*i2);
			for(i3 = s4.begin(); i3 != s4.end(); i3++){
				string b = *i3, t1 = "" ,t2 = "";
				char c1 = a[0], c2 = b[0];
				t1 += a, t2 += b;
				t1[0] = c2, t2[0] = c1;
				if(s1.find(t1) != s1.end() && s1.find(t2) != s1.end()){
					ans++;
				}
			}
		}
		cout<<ans*2<<endl;
	}
}
