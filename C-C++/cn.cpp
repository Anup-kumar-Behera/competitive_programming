#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int graph[MAX][MAX];
int V;
int minDistance(int dist[], 
				bool sptSet[], int V) 
{ 

	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && 
				dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void printPath(int parent[], int j) 
{ 

	if (parent[j] == - 1) 
		return; 

	printPath(parent, parent[j]); 

	printf("%d ", j); 
} 

int printSolution(int dist[], int n, 
					int parent[]) 
{ 
	int src = 0; 
	printf("Vertex\t Distance\tPath"); 
	for (int i = 1; i < n; i++) 
	{ 
		printf("\n%d -> %d \t\t %d\t\t%d ", 
					src, i, dist[i], src); 
		printPath(parent, i); 
	} 
} 
 
void dijkstra(int graph[MAX][MAX], int src, int V) 
{ 

	int dist[V]; 

	bool sptSet[V]; 

	int parent[V]; 

	for (int i = 0; i < V; i++) 
	{ 
		parent[0] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = false; 
	} 

	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) 
	{ 

		int u = minDistance(dist, sptSet, V); 

		sptSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (!sptSet[v] && graph[u][v] && 
				dist[u] + graph[u][v] < dist[v]) 
			{ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
	} 

	printSolution(dist, V, parent); 
} 

void printWeightMatrix(int graph[MAX][MAX], int V){
	cout<<endl<<"Printing weight matrix: \n";
	
	cout<<"		";
	for(int i = 0; i < V; i++){
		cout<<i<<"    ";
	}
	cout<<endl<<endl;
	for(int i = 0; i < V; i++){
		cout<<"node "<<i<<":		";
		for(int j = 0; j < V; j++){
			cout<<graph[i][j]<<"    ";
		}
		cout<<endl;
	}
}
void detectingNeighbours(int graph[MAX][MAX], int V){
	cout<<endl<<"Printing the neibour nodes of each node:\n";
	
	for(int i = 0; i < V; i++){
		cout<<"node "<<i<<" :";
		for(int j = 0; j < V; j++){
			if(graph[i][j] != 0){
				cout<<j<<" ";
			}
		}
		cout<<endl;
	}
}
void createWeightMatrix(){
	cout<<"Enter number of nodes (V > 10): ";
	//int V;
	cin>>V;
	
	cout<<endl<<"Star topology is used here.\n\n";
	if(V < 10){
		cout<<"number of nodes must be at least 10.\n";
		return ;
	}
	
	cout<<"Enter value for the hub: ";
	int h;
	cin>>h;
	
	memset(graph, 0, sizeof(graph));
	for(int i = 0; i < V; i++){
		cout<<"Enter weight for edge "<<h<<" and "<<i<<" :";
		int w;
		cin>>w;
		
		if(i == h)
			w = 0;
		graph[h][i] = w;
		graph[i][h] = w;
	}
}
void UpdateMatrix(int graph[MAX][MAX], int V){
	cout<<"Enter new value for hub: ";
	int h;
	cin>>h;
	
	
	for(int i = 0; i < V; i++){
		cout<<"Enter weight value for edge "<<h<<" and "<<i<<" :";
		int w;
		cin>>w;
		
		graph[h][i] = graph[i][h] = w;
	}
}
int main() 
{ 
	int n, k = 0;
	do{
		cout<<"\nEnter 1 to createWeightMatrix: \n";
		cout<<"Enter 2 to update WeightMatrix: \n";
		cout<<"Enter 3 to detect Neighbours: \n";
		cout<<"Enter 4 to print shortest path: \n";
		cout<<"Enter 5 to print Matrix: \n";
		cout<<endl;
		cout<<"Enter value from 1 to 5 to select from above: ";
		cin>>n;
		
		if(n == 1){
			createWeightMatrix();
			k = 1;
		}else if(n == 2){
			if(k == 0){
				cout<<"Not Allowed\n";
			}
			
			UpdateMatrix(graph, V);
		}
		else if(n == 3){
			if(k == 0){
				cout<<"Not Allowed\n";
			}
			detectingNeighbours(graph, V);
		}else if(n == 4){
			if(k == 0){
				cout<<"Not Allowed\n";
			}
			dijkstra(graph, 0, V);
		}
		else if(n == 5){
			if(k == 0){
				cout<<"Not Allowed\n";
			}
			printWeightMatrix(graph, V);
		}
	}while(n);
	 
	return 0; 
} 

