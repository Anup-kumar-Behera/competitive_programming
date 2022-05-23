#include<bits/stdc++.h> 
using namespace std; 
# define INF INT_MAX

class Graph 
{ 
	int V;

	list< pair<int, int> > *adj; 

public: 
	Graph(int V); 
 
	void addEdge(int u, int v, int w); 

	void shortestPath(int s); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list< pair<int, int> >[V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

void Graph::shortestPath(int src) 
{ 

	set< pair<int, int> > setds; 

	vector<int> dist(V, INF); 
 
	setds.insert(make_pair(0, src)); 
	dist[src] = 0; 

	while (!setds.empty()) 
	{ 

		pair<int, int> tmp = *(setds.begin()); 
		setds.erase(setds.begin()); 

		int u = tmp.second; 

		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 

			int v = (*i).first; 
			int weight = (*i).second; 

			if (dist[v] > dist[u] + weight) 
			{ 

				if (dist[v] != INF) 
					setds.erase(setds.find(make_pair(dist[v], v))); 

				dist[v] = dist[u] + weight; 
				setds.insert(make_pair(dist[v], v)); 
			} 
		} 
	} 

	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

int main() 
{ 
	int V;
	cout<<"Enter number of nodes (n > 10): ";
	cin>>V;
	
	if(V < 10){
		cout<<"Number of nodes must be > 10\n";
		return 0;
	}
		
	Graph g(V); 

	cout<<"Star topology is used here.\n";
	
	cout<<"Enter value for the hub: ";
	int h;
	cin>>h;
	
	for(int i = 0; i < V; i++){
		cout<<"Enter weight of node "<<i<<" :";
		int w;
		cin>>w;
		if(i == h)
			w = 0;
		g.addEdge(h, i, w); 
		g.addEdge(i, h, w); 
	}

	g.shortestPath(9); 

	return 0; 
} 

