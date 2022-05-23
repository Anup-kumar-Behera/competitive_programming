#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define m 100
int arr[m][m];

void printSol(int arr[][m], int n){
	static int count = 0;
	cout<<"\nPrinting solution: \n";
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	count++;
	cout<<count<<endl;
}
bool isSafe(int arr[][m], int n, int row, int col){
	int r = row-1, c = col;
	while(r >= 0){
		if(arr[r][c])
			return false;
		r--;
	}
	r = row-1, c = col-1;
	while(r >= 0 && c >= 0){
		if(arr[r][c])
			return false;
		r--, c--;
	}
	r = row-1, c = col+1;
	while(r >= 0 && c < n){
		if(arr[r][c])
			return false;
		r--, c++;
	}
	
	return true;
}
void solveNQUtil(int arr[][m], int n, int s){
	if(s == n ){
		printSol(arr, n);
	}
	
	for(int i = 0; i < n; i++){
		if(isSafe(arr, n, s, i)){
			arr[s][i] = 1;
			solveNQUtil(arr, n, s+1);
			arr[s][i] = 0;
		}
	}
	return;
}

void solveNQ(int n){
	memset(arr, 0, 100 * 100 * (sizeof(int)));
	
	solveNQUtil(arr, n, 0);
}

int main(){
	int n;
	cout<<"Enter size of board: ";
	cin>>n;
	solveNQ(n);
	
}
