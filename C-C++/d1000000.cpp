#include <bits/stdc++.h>
using namespace std;

int main(){
  int t, ts;
  cin>>t;

  for(ts = 1; ts <= t; ts++){
    int n;
    cin>>n;

    long arr[n];

    for(int i = 0; i < n; i++)
      cin>>arr[i];

    sort(arr, arr+n);

    // for(int i = 0; i < n; i++)
      // cout<<arr[i]<<" ";
    long t[n];
    // memset(t, 1, sizeof(t));
    for(int i = 0; i < n; i++)  t[i] = 1;
    for(int i = 1; i < n; i++){
      long tmp = t[i-1];
      if(arr[i] > tmp)
        t[i] += t[i-1];
      else
        t[i] = max(t[i], t[i-1]);
    }
    cout<<"Case #"<<ts<<": ";
    cout<<t[n-1]<<endl;

  }
}
