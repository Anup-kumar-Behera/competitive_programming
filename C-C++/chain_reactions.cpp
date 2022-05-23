#include <bits/stdc++.h>
using namespace std;

int main(){
  int t, ts;
  cin>>t;

  for(ts = 1; ts <= t; ts++){

    int n;
    cin>>n;
    unordered_set<int> st;
    long fun[n+1];
    int pnt[n+1];
    for(int i = 1; i <= n; i++)
      cin>>fun[i];

    for(int i = 1; i <= n; i++){
      cin>>pnt[i];
      st.insert(pnt[i]);
    }

    vector<int> triggers;

    for(int i = 1; i <= n; i++)
      if(st.find(i) == st.end())  triggers.push_back(i);

    vector<vector<int>> v;
    for(int i = 0; i < triggers.size(); i++){
      vector<int> tmp;
      int x = triggers[i];
      int ind = pnt[x];

      tmp.push_back(fun[x]);
      while(ind != 0){
        tmp.push_back(fun[ind]);
        x = ind;
        ind = pnt[ind];
      }
      v.push_back(tmp);
    }
    for(int i = 0; i < v.size(); i++){
      for(int j = 0; j < v[i].size(); j++)
        cout<<v[i][j]<<"->";
      cout<<endl;
    }
  }
}
