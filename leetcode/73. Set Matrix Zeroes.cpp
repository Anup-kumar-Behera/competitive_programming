#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    unordered_set<int> rows, cols;

    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
    }

    for (auto it = rows.begin(); it != rows.end(); it++)
    {
        for (int i = 0; i < n; i++)
            matrix[*it][i] = 0;
    }
    for (auto it = cols.begin(); it != cols.end(); it++)
    {
        for (int i = 0; i < m; i++)
            matrix[i][*it] = 0;
    }
}
int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    setZeroes(matrix);

    cout<<"-------------------------------"<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}