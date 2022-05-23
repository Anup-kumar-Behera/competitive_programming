#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b){
	int n = a;
	
	int c = 0;
	
	while(a != b){
		int x = a+1, y = b+1, z = a|b;
		
		if(abs(b - x) > abs(b-y))
			b = y;
		else if(abs(b-y) > abs(b-z))
			a = z;
		else if(abs(b-x) < abs(b-z))
			a = x;
		
//		if(a < b){
//			int x = a|b, y = a+1;
////			if(x > a)
//			a = max(x, y);
//			
//		}else if(a > b){
//			int x = a|b, y = a-1, z = b+1;
//			
//			int m = min(x, min(y, z));
//			if(m == z)
//				b = z;
//			else
//				a = m;
//		}
			c++;
}
	
	
	return c;
}
int main(){
	int t;
	cin>>t;
	
	while(t--){
		int a, b;
		cin>>a>>b;
		
		cout<<solve(a, b)<<endl;
	}
}
