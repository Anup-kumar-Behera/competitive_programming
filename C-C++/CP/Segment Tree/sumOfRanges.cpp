#include<bits/stdc++.h>
using namespace std;

int getMid(int a, int b){ return a + (b - a)/2; }

int constructSTUtil(int arr[], int l, int h, int *st, int curr){
	if(l == h){
		st[curr] = arr[h];
		return arr[h];
	}
	int mid = getMid(l, h);
	
	st[curr] = constructSTUtil(arr, l, mid, st, curr * 2 + 1) + constructSTUtil(arr, mid+1, h, st, curr * 2 + 2);
	return st[curr];
}
int *constructST(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int mx_size = 2 * (int)pow(2, x)-1;
	int *st = new int[mx_size];
	
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}
int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i < n; i++)
		cin>>arr[i];
	int *st = constructST(arr, n);
	for(int i = 0; i < sizeof(st)/sizeof(st[0]); i++)
		cout<<st[i]<<" ";
	cout<<endl;
	return 0;
}
