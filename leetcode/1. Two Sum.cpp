#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    vector<int> ans;

    unordered_map<int, vector<int>> mp;

    int j = 0;
    for (auto i : nums)
        mp[i].push_back(j++);

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int a = it->first;
        int x = target - a; // it->first;

        if (mp.find(x) != mp.end())
        {
            if (mp[x][0] != it->second[0])
            {
                ans.push_back(it->second[0]), ans.push_back(mp[x][0]);
                return ans;
            }
            else if (it->second.size() > 1)
            {
                ans.push_back(it->second[0]);
                ans.push_back(it->second[1]);
            }
        }
    }
    return ans;
}

int main(){
    int n, target;
    cin>>n>>target;

    vector<int> v(n, 0);

    for(auto &i:v) cin>>i;

    vector<int> ans = twoSum(v, target);

    for(auto i:v)   cout<<i<<" ";
}