#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<int> *adj;
    void bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[], vector<vector<int>> &ans)
    {
        static int time = 0;

        visited[u] = true;

        disc[u] = low[u] = ++time;

        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            int v = *it;

            if (!visited[v])
            {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent, ans);

                low[u] = min(low[u], low[v]);

                vector<int> tmp;
                tmp.push_back(u);
                tmp.push_back(v);

                if (low[v] > disc[u])
                    ans.push_back(tmp);
            }
            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }

public:
    Graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void bridge(vector<vector<int>> &ans)
    {
        bool *visited = new bool[v];
        int *disc = new int[v];
        int *low = new int[v];
        int *parent = new int[v];

        for (int i = 0; i < v; i++)
            visited[i] = false, parent[i] = -1;

        for (int i = 0; i < v; i++)
            if (!visited[i])
                bridgeUtil(i, visited, disc, low, parent, ans);
    }
};
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    Graph g(n);

    for (int i = 0; i < connections.size(); i++)
    {
        g.addEdge(connections[i][0], connections[i][1]);
    }

    vector<vector<int>> ans;
    g.bridge(ans);

    return ans;
}
int main()
{
}