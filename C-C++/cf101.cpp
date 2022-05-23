#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		
		int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MAX, 	m4 = INT_MAX;
		
		m1 = max(a, b);
		m2 = max(c, d);
		m3 = min(a, b);
		m4 = min(c, d);
		
		if(m3 > m2)
			cout<<"NO"<<endl;
		else if(m1 < m4)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	
}
