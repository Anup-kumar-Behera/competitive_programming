#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n, k;
		cin>>n>>k;
		double nk = n * 1.0;
		float ans = (nk/2);
		//cout<<ceil(ans);
		int arr[n];
		int countNegative = 0, sum = 0, countK = 0, bot = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			if(arr[i] < 0)
				countNegative++;
			else{
				sum += arr[i];
				if(arr[i] > k)
					countK++;
				if(arr[i] >= 0 && arr[i] <= 1)
					bot++;
			}
		}
	
		if(ceil(ans) > (n-countNegative))
			cout<<"Rejected"<<endl;
		else if(k > 0 && bot != n){
			cout<<"Too Slow"<<endl;
		}
		else if(bot == n)
			cout<<"Bot"<<endl;
		else 
			cout<<"Accepted"<<endl;
	}
}
