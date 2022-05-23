#include <bits/stdc++.h>
using namespace std;

bool isPal(int n){
  int x = n;
  int y = 0;

  while(n > 0){
    int t1 = n % 10;
    n /= 10;
    y = y * 10 + t1;
  }

  return (y == x);
}
int main(){
  int t;
  cin>>t;
  int it;
  for(it = 1; it <= t; it++){
    int n;
    cin>>n;

    cout<<isPal(n)<<endl;
  }
}
