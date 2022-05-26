#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<int> *adj;

public:
    Graph(int v)
    {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    bool bfs(int s, int d)
    {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(s);
        visited[s] = true;
        while (q.size())
        {
            int u = q.front();
            q.pop();

            for (auto it = adj[u].begin(); it != adj[u].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                }
                if (*it == d)
                    return true;
            }
        }
        return false;
    }
};

bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();

    Graph g(n);

    for (int i = 0; i < arr.size(); i++)
    {
        if (i - arr[i] >= 0)
            g.addEdge(i, i - arr[i]);
        if (i + arr[i] < n)
            g.addEdge(i, i + arr[i]);
    }
    vector<int> v;

    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            v.push_back(i);
    for (auto i : v)
    {
        if (g.bfs(start, i))
            return true;
    }

    return false;
}
int main()
{
    int n, start;
    cin >> n >> start;

    vector<int> v(n, 0);

    for (auto &i : v)
        cin >> i;

    cout<<canReach(v, start)<<endl;
}