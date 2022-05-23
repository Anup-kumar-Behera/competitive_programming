#include<iostream>
using namespace std;

 void buildSegmentTree(int arr[], int *ans, int s, int e, int i){
	if(s == e){
		ans[i] = arr[s];
		return;
	}
	int mid = (s+e)/2;
	buildSegmentTree(arr, ans, s, mid,  2 * i);
	buildSegmentTree(arr, ans, mid+1, e, 2 * i + 1);
	int a = ans[2 * i];
	int b = ans[2 * i + 1];
	
	ans[i] = a+b;
}
void updateTree(int *arr, int *tree, int s, int e, int ni, int idx, int v){
	if(s == e){
		arr[idx] = v;
		tree[ni] = v;
		return;
	}
	
	int mid = (s+e)/2;
	
	if(idx > mid){
		updateTree(arr, tree, mid+1, e, 2 * ni + 1, idx, v);
	}else{
		updateTree(arr, tree, s, mid, 2 * ni, idx, v);
	}
	
	tree[ni] = tree[2 * ni] + tree[ni * 2 + 1];
}
void printArray(int *ans, int n){
	for(int i = 1; i < 2 * n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 2 * n;
	int *ans = new int[k];
	ans[0] = 0;
	buildSegmentTree(arr, ans, 0, n-1, 1);
	printArray(ans, n);
	
	updateTree(arr, ans, 0, n-1, 1, 2, 10);
	printArray(ans , n);
	
}
