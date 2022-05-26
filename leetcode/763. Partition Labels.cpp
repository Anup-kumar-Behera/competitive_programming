#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s){
    if (s.length() == 1)
        return {1};

    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
        mp[s[i]] = i;

    int i = 0, n = s.length();
    vector<int> ans;

    while (i < n)
    {
        int j = i, k = mp[s[i]];
        while (j < k)
        {
            k = max(k, mp[s[j]]);
            j++;
        }
        ans.push_back(k - i + 1);
        i = k + 1;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;

    vector<int> ans = partitionLabels(s);

    for(auto i:ans) cout<<i<<" ";
}