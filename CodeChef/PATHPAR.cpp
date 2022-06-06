#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n, k;
       cin>>n>>k;
       
        if(n % 2 == 1 && k == 0)
            cout<<"NO"<<endl;
        else if(n > 0 && k > 0 && n+k % 2 == 1) 
            cout<<"YES"<<endl;
        else
            cout<<"YES"<<endl;
    }
}