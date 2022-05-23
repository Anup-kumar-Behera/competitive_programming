#include <bits/stdc++.h>
using namespace std;

int main(){
  int t, ts;
  cin>>t;

  for(ts = 1; ts <= t; ts++){
    int A[4], B[4], C[4];

    for(int i = 0; i < 4; i++)
      cin>>A[i];
    for(int i = 0; i < 4; i++)
      cin>>B[i];
    for(int i = 0; i < 4; i++)
      cin>>C[i];

    long s = 0;
    for(int i = 0; i < 4; i++){
      s += min(A[i], min(B[i], C[i]));
    }
    cout<<s<<endl;
    cout<<"Case #"<<ts<<": ";
    if(s < 1000000){
      cout<<"IMPOSSIBLE"<<endl;
    }else{
      long x = s - 1000000;

      for(int i = 0; i < 4; i++){
        int m = min(A[i], min(B[i], C[i]));
        if(x < m){
          // x = 0;
          m = m - x;
          x = 0;
        }else{
          x = x-m;
          m = 0;
        }
        cout<<m<<" ";
    }
    cout<<endl;
  }
}
}
