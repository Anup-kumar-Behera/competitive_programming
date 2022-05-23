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
			while(arr[j+mp[arr[i]]] != -1){
				ans++;
				cout<<"ans"<<ans<<endl;
				//j += mp[arr[i]];
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

//#include <bits/stdc++.h>
//using namespace std;
//long int ans = 0;// ma = 0;
////set<long int> st;
//void simpleSieve(int limit, vector<int> &prime)
//{
//	bool mark[limit+1];
//	memset(mark, true, sizeof(mark));
//
//	for (int p=2; p*p<limit; p++)
//	{
//		if (mark[p] == true)
//		{
//			for (int i=p*p; i<limit; i+=p)
//				mark[i] = false;
//		}
//	}
//
//	for (int p=2; p<limit; p++)
//	{
//		if (mark[p] == true)
//		{
//			prime.push_back(p);
//			//cout << p << " ";
//			//st.insert(p);
//			ans++;
//			
//		}
//	}
//	//ma = 1;
//}
//
//void segmentedSieve(int n)
//{
//	int limit = floor(sqrt(n))+1;
//	vector<int> prime; 
//	simpleSieve(limit, prime); 
//
//	int low = limit;
//	int high = 2*limit;
//
//	while (low < n)
//	{
//		if (high >= n) 
//		high = n;
//
//		bool mark[limit+1];
//		memset(mark, true, sizeof(mark));
//
//		for (int i = 0; i < prime.size(); i++)
//		{
//
//			int loLim = floor(low/prime[i]) * prime[i];
//			if (loLim < low)
//				loLim += prime[i];
//
//			for (int j=loLim; j<high; j+=prime[i])
//				mark[j-low] = false;
//		}
//
//		for (int i = low; i<high; i++)
//			if (mark[i - low] == true){
//				//cout << i << " ";
//				ans++;
//				//st.insert(i);
//			}
//
//		low = low + limit;
//		high = high + limit;
//	}
//}
//
//int main()
//{
//	int t;
//	cin>>t;
//	//mark = 0;
//	while(t--){
//		ans = 0;
//		int n, y;
//		cin>>n>>y;
//		
//		segmentedSieve(n+1);
//		//cout<<endl<<"ans :"<<ans<<endl;
//		//cout<<st.size()<<endl;
//		if(ans > y)
//			cout<<"Divyam"<<endl;
//		else
//			cout<<"Chef"<<endl;
//		//set<long int>::iterator it;
//		//for(it = st.begin(); it != st.end(); it++)
//			//cout<<*it<<" ";
//		//cout<<ans<<endl;
//		//st.clear();
//	}
//	return 0;
//}

