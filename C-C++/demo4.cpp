#include <bits/stdc++.h> 
#include <cmath> 
using namespace std; 
typedef long long int ll;
void findX(ll arr[], int n) 
{ 
	ll* itr = max_element(arr, arr + n); 

	ll p = log2(*itr) + 1; 

	ll X = 0; 
	for (ll i = 0; i < p; i++) { 
		long int count = 0; 
		for (ll j = 0; j < n; j++) { 

			if (arr[j] & (1 << i)) { 
				count++; 
			} 
		} 


		if (count > (n / 2)) { 

			X += 1 << i; 
		} 
	} 

	ll sum = 0; 
	for (ll i = 0; i < n; i++) 
		sum += (X ^ arr[i]); 

	cout << sum <<endl; 
} 

int main() 
{ 
	long t;
	cin>>t;
	for(long int i = 0; i < t; i++){
		ll arr[2], a, b;
		cin>>a>>b;
		arr[0] = a;
		arr[1] = b;
		
		findX(arr, 2);
	}

	return 0; 
} 

