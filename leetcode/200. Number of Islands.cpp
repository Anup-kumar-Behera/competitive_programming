#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>> &grid){
    int ans = 0;
    int r[4] = {-1, 0, 0, 1}, c[4] = {0, -1, 1, 0};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;

                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '2';

                while (q.size())
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first, y = p.second;
                    for (int k = 0; k < 4; k++)
                    {
                        if (x + r[k] >= 0 && x + r[k] < grid.size() && y + c[k] >= 0 && y + c[k] < grid[0].size() && grid[x + r[k]][y + c[k]] == '1')
                        {
                            grid[x + r[k]][y + c[k]] = '2';
                            q.push({x + r[k], y + c[k]});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    
}