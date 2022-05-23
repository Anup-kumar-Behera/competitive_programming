#include<bits/stdc++.h>
using namespace std;

void solve1(bool *arr, int n){
	
	
	
	for(int p = 2; p * p < n; p++){
		if(arr[p]){
			for(int j = p * p; j < n; j += p)
				arr[j] = false;
		}
	}
	arr[0] = arr[1] = false;
	
}
void solve2(int *arr, int n){
	for(int i = 3; i < n; i+= 2)
		arr[i] = 1;// assume all odd numbers as prime
	
	for(int i = 3; i < n; i++)
		if(arr[i] == 1){
			for(int j = i * 2; j < n; j += i)
				arr[j] = 0;
		}
	arr[0] = arr[1] = 0;
	arr[2] = 1;
}
void solve3(int *arr, int n){
	for(int i = 3; i < n; i+=2)
		arr[i] = 1;//all odd numbers are prime
		
	for(int i = 3; i < n; i++)
		if(arr[i] == 1)
			for(int j = i * i; j < n; j+= i)
				arr[j] = 0;
				
	arr[0] = arr[1] = 0;
	arr[2] = 1;
	
	 
}
int main(){
	int n = 150;
	bool arr[n+1];
	memset(arr, true, sizeof(arr));
	int brr[n] = {0};
	int crr[n] = {0};
	
	solve1(arr, n);
	solve2(brr, n);
	solve3(crr, n);
	for(int i = 0; i < n; i++)
		if(arr[i])
			cout<<i<<" ";
	cout<<endl;
	for(int i = 0; i < n; i++)
		if(brr[i] == 1)
			cout<<i<<" ";
	cout<<endl;
	for(int i = 0; i < n; i++)
		if(crr[i] == 1)
			cout<<i<<" ";
}
