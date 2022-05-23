#include<bits/stdc++.h>
#include<string>
using namespace std;

string to_string(int n){
	
	string a = "";
	
	while(n > 0){
		int r = n % 10;
		n /= 10;
		if(r == 0)
			a += '0';
		else if(r == 1)
			a += '1';
	}
	reverse(a.begin(), a.end());
	return a;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		int a;
		cin>>a;
		string s = to_string(a);
		string ans = "";
		ans += '1';
		int c[n];
		c[0] = ans[0] - 48 + s[0] - 48;
		for(int i = 1; i < s.length(); i++){
			/*if((s[i] - 48) + 0 != c[i-1] && c[i-1] == 2){
				if(c[i-1] == )
				ans += '0';
				c[i] = (s[i] - 48)+0;
			}
			else if((s[i] - 48) + 1 == c[i-1]){
				ans += '1';
				c[i] = (s[i] - 48) +1;
			}*/
			if(s[i] == '1'){
				if(s[i]-48 + 1 != c[i-1] && (s[i] - 48) != c[i-1]){
					ans += '1';
					c[i] = (s[i] - 48) + 1;
				}
				if(s[i] - 48 + 1 != c[i-1]){
					ans += '1';
					c[i] = (s[i] - 48) +1;
				}
				if(s[i] - 48 != c[i-1]){
					ans += '0';
					c[i] = (s[i] - 48);
				}
			}
			if(s[i] == 0){
				if(s[i] - 48 != c[i-1] && (s[i] - 48) + 1 != c[i-1]){
					ans += '1';
					c[i] =  (s[i] - 48) + 1;
				}
				if(s[i] - 48 != c[i-1]){
					ans += '0';
					c[i] = s[i] - 48;
				}
				if((s[i] - 48) + 1 != c[i-1]){
					ans += '1';
					c[i] = (s[i] - 48) + 1;
				}
			}
		}
		cout<<ans<<endl;
	}
}
