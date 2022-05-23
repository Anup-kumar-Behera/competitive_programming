#include<iostream>
#include<utility>
#include<bits/stdc++.h>
using namespace std;

/*#define MAXN 1000000
#define SQSIZE 1000000

int input[MAXN];
int block[SQSIZE];
int blk_size;*/

/*void preprocess(int arr[], int n){
	int blk_index = -1;
	
	blk_size = sqrt(n);
	
	for(int i = 0; i < n; i++){
		input[i] = arr[i];
		if(i % blk_size == 0){
			blk_index++;
		}
		block[blk_index] += arr[i];
	}
}*/
//static int last;
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void solve(int arr[], int n, int a, int b, int s){
	int last = 0;
	int l = (a + (s * last) - 1) % n + 1;
	int r = (b + (s * last) - 1) % n + 1;
	if(l > r){
		swap(&l, &r);
	}
	int c = 0;
	for(int j = l - 1; j < r; j++){
		if(arr[j] > last){
			last = arr[j];
			c++;
		}
	}
	cout<<c<<endl;
	
}
int main(){
	//last = 0;
	int n, q, s;
	cin>>n>>q>>s;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	//pair<int, int> p[q];
	for(int i = 0; i < q; i++){
		int a, b;
		cin>>a>>b;
		solve(arr, n, a, b,s );
	}
}
