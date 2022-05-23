#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int k = 3;
		map<int, int> m1, m2;
		for(int j = 0; j < k; j++){
			cin>>m1[j];
		}
		for(int j = 0; j < k; j++){
			cin>>m2[j];
		}
		int ans = 0;
		if(m1[2] <= m2[1])
			ans += 2 * m1[2];
		else
			ans += 2 * m2[1];
		if(m1[1] > m2[2])
			ans += m2[2];
		else
			ans += m1[1];
		cout<<ans<<endl;
	}
	
		
	return 0; 
} 
