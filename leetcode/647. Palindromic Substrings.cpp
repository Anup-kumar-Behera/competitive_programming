#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> mat(n, vector<int> (n, 0));
        
        int ans = n;
        for(int i = 0; i < n; i++)
            mat[i][i] = 1;
        
        for(int i = 0, j = 1; i < n-1; i++, j++){
            if(s[i] == s[j])
                mat[i][j] = 1, ans++;
        }
        int i = 0, j = 2;
        
        while(j < n){
            int i1 = 0, j1 = j;
            
            for(i1, j1; j1 < n ; i1++, j1++)
                if(s[i1] == s[j1] && mat[i1+1][j1-1] == 1)
                    mat[i1][j1] = 1, ans++;
            
            j++;
        }
        
        return ans;
    }
};

int main(){
    string s;
    cin>>s;

    Solution sol;
    cout<<sol.countSubstrings(s)<<endl;
}