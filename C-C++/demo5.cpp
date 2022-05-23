#include<bits/stdc++.h>
using namespace std;

int solve(map<int, int> mp, queue<int> &q, int *a, int *b, int n){
	int arr[10];
	memset(arr, -1, 10 * sizeof(int));
	for(int i = 0; i < n; i++)
		arr[i] = a[i];
	q.pop();
	int ans = 0;
	for(int i = 0; i < 10; i++){
		if(q.empty())
			break;
		if(arr[i] > 0 && arr[i] > q.front()){
			q.pop();
			q.push(arr[i]);
			//int temp = arr[i];
			int j = i;
			while(arr[j] != -1){
				ans++;
				//cout<<"ans"<<ans<<endl;
				j += mp[arr[i]];
			}
			arr[j] = arr[i];
			arr[i] = -1;
		}else if(arr[i] > 0 && arr[i] < q.front()){
			q.pop();
		}
	}
	cout<<"start\n";
	for(int i = 0; i < 10; i++)
		cout<<arr[i]<<endl;
	cout<<"end\n";
	return ans;
}
int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		int a[n], b[n];
		
		queue<int> q;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			q.push(a[i]);
		}
		
		map<int, int> mp;
		map<int, int>::iterator it;
		for(int i = 0; i < n; i++){
			cin>>b[i];
			mp[a[i]] = b[i];
		}
		
		cout<<solve(mp, q, a, b, n)<<endl;
		
		
	}
}
