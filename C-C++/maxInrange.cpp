#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> arr, vector<vector<int> > &t)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
		t[i][0] = arr[i];

	for (int j = 1; (1 << j) <= n; j++) {

		for (int i = 0; (i + (1 << j) - 1) < n; i++) {

			if (t[i][j - 1] > t[i + (1 << (j - 1))][j - 1])
				t[i][j] = t[i][j - 1];
			else
				t[i][j] = t[i + (1 << (j - 1))][j - 1];
		}
	}
}

int query(int L, int R, vector<vector<int> > t)
{

	int j = (int)log2(R - L + 1);

	if (t[L][j] >= t[R - (1 << j) + 1][j])
		return t[L][j];

	else
		return t[R - (1 << j) + 1][j];
}
static bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}
int main()
{


	int n, m;
	cin>>n;
	cin>>m;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	vector<vector<int> > t(n+2, vector<int> (n+2, 0));
	solve(v, t);
	
	int ans = 0;
	
	int left[m], right[m];
	for(int i = 0; i < m; i++)
		cin>>left[i];
	for(int i = 0; i < m; i++)
		cin>>right[i];
	
	vector<pair<int, int> > p;
	for(int i = 0; i < m; i++){
		p.push_back({left[i]-1, right[i]-1});
	}
	for(int i = 0; i < m; i++){
		cout<<"f: "<<p[i].first<<", s: "<<p[i].second<<endl;
	}
	cout<<"after"<<endl;
	sort(p.begin(), p.end(), cmp);
	for(int i = 1; i < m; i++){
		if(p[i].first <= p[i-1].second){
			int x = p[i].first;
			
			p[i].first = p[i-1].second+1;
			p[i-1].second = x-1;
		}
	}
	for(int i = 0; i < m; i++){
		int x;
		if(p[i].first >= 0 && p[i].second >= 0 && p[i].first >= p[i].second)
			x = query(p[i].first, p[i].second, t);
//		cout<<"x: "<<x<<endl;
		ans += x;
		cout<<"f: "<<p[i].first<<", s: "<<p[i].second<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

