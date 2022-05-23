#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <stdio.h> 
#include <limits.h> 
   
#define MAX 5
   
int minDistance(int dist[], bool sptSet[], int V) 
{ 
  
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   int printSolution(int dist[], int src, int V) 
{ 
   printf("Link State Routing Table for router %d \n____________________________________\n",src+1); 
   for (int i = 0; i < V; i++) 
      printf("%d \t \t %d\n", i+1, dist[i]); 
      
    printf("\n\n");
} 

void dijkstra(int graph[MAX][MAX], int src, int V) 
{ 
     int dist[V];     
   
     bool sptSet[V]; 
   
  
     for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V-1; count++) 
     { 
        
       int u = minDistance(dist, sptSet, V); 
   
       
       sptSet[u] = true; 
   
       
       for (int v = 0; v < V; v++) 
   
       
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
   
        printSolution(dist,src, V);     
} 

int main()
{ 
	int graph[MAX][MAX] = {0};
    printf("Enter number of Nodes: ");
    int V;
    scanf("%d", &V);
    printf("\n");
    for(int i = 0; i < V; i++)
    	for(int j = 0; j < V; j++){
    		printf("Enter cost matrix value for[%d][%d]: ", i, j);
    		scanf("%d", &graph[i][j]);
		}
    
 for(int i =0; i <V;i++)
 {
  dijkstra(graph, i, V);
}
	return 0;
}
