#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int arr[3], brr[3];

        cin>>arr[0]>>arr[1]>>arr[2];
        cin>>brr[0]>>brr[1]>>brr[2];

        int s1 = arr[0] + arr[1] + arr[2];
        int s2 = brr[0] + brr[1] + brr[2];

        if(s1 > s2){
            cout<<"DRAGON"<<endl;
        }else if(s1 < s2){
            cout<<"SLOTH"<<endl;
        }else{
            if(arr[0] > brr[0]){
                cout<<"DRAGON"<<endl;
            }else if(arr[0] < brr[0]){
                cout<<"SLOTH"<<endl;
            }else{
                if(arr[1] > brr[1]){
                    cout<<"DRAGON"<<endl;
                }else if(arr[1] < brr[1]){
                    cout<<"SLOTH"<<endl;
                }else{
                    cout<<"TIE"<<endl;
                }
            }
        }
    }
}