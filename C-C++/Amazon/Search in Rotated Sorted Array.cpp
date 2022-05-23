#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> arr, int l, int h){
  while(l <= h){
    int m = l + (h-l)/2;

    if(arr[m] > arr[m+1] && m+1 < arr.size())  return m;
    if(arr[m] < arr[m-1] && m-1 >= 0) return m-1;
    if(arr[m] > arr[h])
      l = m+1;
    else
      h = m-1;

  }
  return -1;
}
int binary_search(vector<int> arr, int l, int h, int t){
  while(l <= h){
    int m = l + (h-l)/2;

    if(arr[m] == t) return m;
    else if(arr[m] < t)
      l = m+1;
    else
      h = m-1;
  }
  return -1;
}
int main(){
  vector<int> arr;
  // arr.push_back(4);
  // arr.push_back(5);
  // arr.push_back(6);
  // arr.push_back(7);
  // arr.push_back(0);
  // arr.push_back(1);
  // arr.push_back(2);

  arr.push_back(1);
  // arr.push_back(2);
  arr.push_back(3);


  int l = 0, h = arr.size()-1;
  int p = findPivot(arr, l, h);
  int a = -1, b = -1;
  int t = 0;
  if(p != -1){
    a = binary_search(arr, l, p, t);
    b = binary_search(arr, p+1, h, t);
  }else
    a = b = binary_search(arr, l, h, t);

  if(a >= 0)
    cout<<a<<endl;
  else if(b >= 0)
    cout<<b<<endl;
  else
    cout<<-1<<endl;
}
