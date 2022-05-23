#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 
int main(){
	int n, q;
	cin>>n>>q;
	
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
		
	for(int i = 0; i < q; i++){
		int idx, val;
		cin>>idx>>val;
		
		arr[idx-1] *= val;
		cout<<findGCD(arr, n)<<endl;
	}
		
	
}
