#include <bits/stdc++.h>
using namespace std;

string solve(string s, string t){
  int m = s.length(), n = t.length();

  if(m < n)
    return "";

  unordered_map<char, int> ms, mt;
  for(auto x:s)
    ms[x]++;
  for(auto x:t)
    mt[x]++;

  int i = 0, j = m-1;

  char c = s[i];
  while (mt.find(c) != mt.end() && ms[c] > mt[c]) {
    ms[c]--;
    i++;
    c = s[i];
  }

  c = s[j];
  while(mt.find(c) != mt.end() && ms[c] > mt[c]){
    ms[c]--;
    j--;
    c = s[j];
  }

  while(i < j){
    cout<<s[i++];
  }
  cout<<endl;
  return "ANUP";
}
int main(){
  string s, t;
  cin>>s>>t;

  cout<<solve(s, t)<<endl;
}
