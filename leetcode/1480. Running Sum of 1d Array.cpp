#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    int s = 0;
    vector<int> v;

    for (auto x : nums)
        v.push_back(s += x);
    return v;
}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (auto &x : v)
        cin >> x;
    
    vector<int> tmp = runningSum(v);

    for(auto x:tmp) cout<<x<<" ";
}