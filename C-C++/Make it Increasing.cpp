#include <bits/stdc++.h>
using namespace std;

bool is_increasing(vector<long> v, int n){
  for(int i = 1; i < n; i++)
    if(v[i] < v[i-1]) return false;
  return true;
}
bool is_decreasing(vector<long> v, int n){
  for(int i = 1; i < n; i++)
    if(v[i] > v[i-1]) return false;
  return true;
}
int solve(vector<long> v, int n){

  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    vector<long> b(n, 0);
    int c = 0;
    int j = i-1, k = i+1;
    while(j >= 0){
      if(abs(v[j]) > abs(v[j+1])){
        b[j] = -v[j];
        c += 1;
      }else{
        int x = abs(v[j+1])/abs(v[j]);
        long y = abs(v[j]) * (x+1);
        b[j] = -y;
        c += x;
      }
      j--;
    }
    while(k < n){
      if(v[k] > v[k-1]){
        b[k] = v[k];
        c += 1;
      }else{
        int x = b[k-1] / v[k];
        long y = (x+1) * v[k];
        b[k] = y;
        c += (x+1);
      }
      k++;
    }
    ans = min(ans, c);
    for(auto x:b) cout<<x<<" ";
    cout<<endl;
  }
  return ans;
}
int main(){
  int t;
  cin>>t;

  while(t--)  {
    int n;
    cin>>n;

    vector<long> v;
    for(int i = 0; i < n; i++){
      long x;
      cin>>x;

      v.push_back(x);
    }

    if(is_increasing(v, n) || is_decreasing(v, n)){
      cout<<n-1<<endl;
    }else{
      cout<<solve(v, n)<<endl;
    }
  }
}
