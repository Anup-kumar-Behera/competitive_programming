#include <bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	vector<int> *adj;
public:
	Graph(int v){
		this->v = v;
		adj = new vector<int> [v];
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int u, int d, vector<bool> &visited, vector<int> &path, vector<vector<int> > &ans){
		visited[u] = true;
		path.push_back(u);
		if(u == d){
			ans.push_back(path);
			return;
		}else{
			vector<int>::iterator it;
			for(it = adj[u].begin(); it != adj[u].end(); it++)
				if(!visited[*it])
					dfs(*it, d, visited, path, ans);
		}
		path.pop_back();
	}
};
int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n, q;
		cin>>n>>q;
		Graph g(n+1);
		vector<int> arr;
		map<pair<int, int>, int> mp;
		
		for(int i = 0; i < n; i++){
			int x;
			cin>>x;
			arr.push_back(x);
		}
		
		for(int i = 0; i < n-1; i++){
			int a, b, c;
			cin>>a>>b>>c;
			
			g.addEdge(a, b);
			mp[{a, b}] = c, mp[{b, a}] = c;
			
		}
		vector<vector<int> > aa; 
		for(int i = 0; i < q; i++){
			int a, b;
			cin>>a>>b;
			vector<bool> vis(n+1, false);
			vector<int> path;
//			cout<<solve()<<endl;
			
			
			g.dfs(a, b, vis, path, aa);
			
			
		}
		for(int i = 0; i < q; i++){
			vector<int> path = aa[i];
//			for(int i = 0; i < path.size(); i++)
//				cout<<path[i]<<" ";
//			cout<<endl;
			int pathSum[path.size()];
			pathSum[0] = 0;
			for(int i = 1; i < path.size(); i++)
				pathSum[i] = pathSum[i-1] + mp[{path[i], path[i-1]}];
			long long int ans = 0;
			
			for(int i = 0; i < path.size(); i++){
				ans += arr[path[i]-1] * (pathSum[i] - (pathSum[path.size()-1] - pathSum[i]));
			}
			cout<<ans<<endl;
		}
	}
}
