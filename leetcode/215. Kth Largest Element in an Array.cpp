#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size()-k];
    }
};

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n, 0);
    for(auto &i:arr)    cin>>i;

    Solution s;
    cout<<s.findKthLargest(arr, k)<<endl;
}