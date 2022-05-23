#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() 
{ 
   int n;
   cin>>n;
   pair<int, int> p[n];
   vector<int> v1, v2;
   cin>>p[0].first>>p[0].second;
   for(int i = 1; i < n; i++)
   {    
       int a, b;
       cin>>a>>b;
       p[i].first = p[i-1].first+a;
       p[i].second = p[i-1].second+b;
   }
    //vector<int> v1, v2;
   for(int i = 0; i < n; i++){
       //cout<<p[i].first<<" "<<p[i].second<<endl;
       //p[i].first = p[i-1].first;
       //p[i].second = p[i-1].second;
       if(p[i].first > p[i].second){
       		v1.push_back(p[i].first - p[i].second);
	   }
	   else if(p[i].first < p[i].second){
       		v2.push_back(p[i].second - p[i].first);
	   }
   }
   	if(*max_element(v1.begin(), v1.end()) > *max_element(v2.begin(), v2.end()))
   		cout<<1<<" "<<*max_element(v1.begin(), v1.end())<<endl;
	else
		cout<<2<<" "<<*max_element(v2.begin(), v2.end())<<endl;
   
   return 0;
} 
