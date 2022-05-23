#include<bits/stdc++.h>
using namespace std;

void solve(int n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	
	for(int p = 2; p*p <= n; p++){
		if(prime[p] == true){
			for(int i = p*p; i <= n; i += p)
				prime[i] = false;
		}
	}
	
	for(int p = 2; p <= n; p++)
		if(prime[p])	
			cout<<p<<" ";
	cout<<endl;
}
int main(){
	cout<<"Enter an integer: ";
	int n;
	cin>>n;
	
	cout<<"\nFollowing are the prime numbers smaller or equql to "<<n<<endl;
	solve(n);
	
	return 0;
}
