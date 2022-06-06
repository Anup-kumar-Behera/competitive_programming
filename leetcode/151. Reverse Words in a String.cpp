#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = ""  ;
        string tmp = "";
        reverse(s.begin(), s.end());
        s += ' ';
        for(auto c:s){
            if(c == ' '){
                if(tmp.length()){
                    reverse(tmp.begin(), tmp.end());
                    ans += tmp + ' ';
                    tmp = "";
                }
            }else
                tmp += c;
        }
        ans.pop_back();
        
        return ans;
    }
};
int main(){
    string s;
    getline(cin, s);

    Solution v;
    cout<<v.reverseWords(s)<<endl;
}