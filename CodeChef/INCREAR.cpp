#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long a, b;
        cin>>a>>b;
        
        if(a == b){
            cout<<0<<endl;
        }else if(a < b){
                cout<<b-a<<endl;
        }else{
            int x = (a-b)/2;
            
            if(x * 2+b >= a){
                cout<<x<<endl;
            }else{
                cout<<x+2<<endl;
            }
        }
        
    }
}