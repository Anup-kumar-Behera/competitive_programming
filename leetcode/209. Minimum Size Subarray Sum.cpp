#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    queue<int> q;
    int s = 0, ans = INT_MAX;
        
    for(int i = 0; i < nums.size(); i++){
        s += nums[i];
        q.push(nums[i]);

        while(s >= target){
            int a = q.size();
            ans = min(ans, a);
                
            int x = q.front();
            q.pop();                    
            s -= x;
        }
    }
    return (ans == INT_MAX)?0:ans;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n, target;
        cin>>n>>target;

        vector<int> v(n, 0);

        for(auto &i : v)    cin>>i;

        cout<<minSubArrayLen(target, v)<<endl;
    }
}