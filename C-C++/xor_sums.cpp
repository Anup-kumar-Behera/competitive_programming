#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	long int arr[n];
	long int max = INT_MIN;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(max < arr[i])
			max = arr[i];
	}
	long int bits = (int)log2(max) + 1;

	map<int, int> Ones;
	map<int, int> Zeros;
	map<int, int>::iterator it;// Zeros;

	for(int i = 0; i < n; i++){
		int temp = 1;
		for(int j = 1; j <= bits; j++){
			if(arr[i] & (temp= 1 << j-1)){
				Ones[j]++;
			}
			else{
				Zeros[j]++;
			}
		}
	}
	
	cout<<"Ones"<<endl;
	for(it = Ones.begin(); it != Ones.end(); it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}
	cout<<endl<<"Zeros"<<endl;
	for(it = Zeros.begin(); it != Zeros.end(); it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int m;
		cin>>m;
		
		
	}
	cout<<bits<<endl;
	
}
