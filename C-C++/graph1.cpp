#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int a, int b);
		void bfs(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int a, int b){
	adj[a].push_back(b);
//	adj[b].push_back(a);
}

void Graph::bfs(int s){
	bool *visited = new bool[V];
	
	for(int x = 0; x < V; x++){
		visited[x] = false;
	}
	
	visited[s] = true;
	queue<int> q;
	q.push(s);
	list<int>::iterator it;
	while(!q.empty()){
		s = q.front();
		q.pop();
		cout<<s<<" ";
		
		for( it = adj[s].begin(); it != adj[s].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
			}
		}
		
	}
	
}

int main(){
	
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	cout<<"bfs: \n"<<endl;
	g.bfs(0);
}
