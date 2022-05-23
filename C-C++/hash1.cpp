#include<bits/stdc++.h>
using namespace std;

void hashing(int arr[], int n){

	map<int, int> m;
	
	for(int i = 0; i < n; i++)
		m[arr[i]]++;
	map<int, int>::iterator j;
	for(j = m.begin(); j != m.end(); ++j)
		if(j->second > (n/2))
			cout<<j->first;
}

int main(){
	int arr[]={3,1,3,3,2};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	hashing(arr, n);
	return 0;
}
