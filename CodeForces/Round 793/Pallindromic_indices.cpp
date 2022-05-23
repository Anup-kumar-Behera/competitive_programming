#include <bits/stdc++.h>
using namespace std;

bool isPal(string s){
    int i = 0, j = s.length()-1;

    while(i <= j){
        if(s[i++] != s[j--])
            return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int c = 0;
        for(int i = 0; i < s.length(); i++){
            string a = "", b = "";//, c = "", d = "";

            if(i-1 >= 0){
                a += s.substr(0, i);
            }
            if(i+1 < n){
                b += s.substr(i+1, n-i-1);
            }
            // cout<<a+b<<"    "<<b+a<<endl;
            if(isPal(a+b)){
                  c++;
                //   cout<<1<<endl;
            }
        }
        cout<<c<<endl;
    }
}