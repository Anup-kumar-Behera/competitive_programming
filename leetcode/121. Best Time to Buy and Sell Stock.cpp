#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left[n], right[n];
        
        left[0] = prices[0];
        right[n-1] = prices[n-1];
        
        for(int i = 1; i < n; i++)
            left[i] = min(prices[i], left[i-1]);
        
        for(int i = n-2; i >= 0; i--)
            right[i] = max(prices[i], right[i+1]);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, (right[i]-left[i]));
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> arr(n, 0);
    for(auto &i:arr)    cin>>i;

    Solution s;
    cout<<s.maxProfit(arr)<<endl;
}