#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, double> const &p1, pair<int, double> const &p2)
    {
        return p1.second > p2.second;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> pq;

    int j = 0;
    for (auto i : points)
    {
        double x = pow((double)(i[0] * i[0] + i[1] * i[1]), 0.5);
        pq.push({j++, x});
    }

    vector<vector<int>> ans;

    while (k-- > 0)
    {
        pair<int, double> p = pq.top();
        pq.pop();

        ans.push_back(points[p.first]);
    }
    return ans;
}

int main(){
}