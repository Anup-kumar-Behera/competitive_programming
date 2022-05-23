#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int x){
    int n = v.size();

    sort(v.begin(), v.end());

    int c = 0;

    int s = 0;
    for(int i = n-1; i >= 0; i--){
        if(s >= x)
            break;
        c++;
        s += v[i];
    }

    return (s >= x)?c:-1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;

        vector<int> v;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        cout<<solve(v, x)<<endl;
    }
}