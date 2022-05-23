#include<bits/stdc++.h>
using namespace std;

bool prime[1000001];
int ans[1000001];
void sieve(){
    memset(prime, true, sizeof(prime));
    for(int i = 2; i * i <= 1000001; i++){
			if(prime[i]){
				for(int j = i*i; j <= 1000001; j+= i){

					prime[j] = false;
				}
			}
		}
	
	ans[2] = 1;
	for(int i = 3; i <= 1000001; i++){
	    if(prime[i]){
	        ans[i] = ans[i-1]+1;
	    }
	    else{
	        ans[i] = ans[i-1];
	    }
	}
}
int main(void) 
{ 
    sieve();
	int t;
	cin>>t;
	
	while(t--){
		int n, y;
		//scanf("%d %d", &n, &y);	
		cin>>n>>y;
		//int ans = 0;
	
		
		//cout<<"ans:"<<ans<<endl;
		//cout<<"prime[n]: "<<ans[n]<<endl;
		if(ans[n] > y)
			cout<<"Divyam"<<'\n';
		else
			cout<<"Chef"<<'\n';
	}

	return 0; 
} 

