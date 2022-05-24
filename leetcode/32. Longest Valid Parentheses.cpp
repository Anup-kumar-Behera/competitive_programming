#include <bits/stdc++.h>
using namespace std;

int solve(string s){
  stack<pair<char, int>> st;

  st.push({'$', 0});

  int ans = 0;
  for(int i = 0; i < s.length(); i++){
    if(st.size() == 1){
      st.push({s[i], i+1});
    }else if(st.size() > 1){
      pair<char, int> p = st.top();

      if(p.first == '(' && s[i] == ')'){
        st.pop();
        ans = max(ans, i+1 - st.top().second);
      }
      else
      st.push({s[i], i+1});
    }
  }
  return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
      cin>>s;

      cout<<solve(s)<<endl;
    }
}
