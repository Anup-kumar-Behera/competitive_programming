#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[20];
    cout<<"Enter a string: ";
    cin>>s;
    int l = strlen(s);
    int a[26];
    int i;
    for(i = 0; i < 26; i++) 
        a[i] = 0;
    for(i=0;i<l;i++)
    {
        a[s[i]-65]=a[s[i]-65]+1;
    }
    for(i = 0; i < 26; i++)
    {
        cout<<" "<<a[i];
    }

    return 0;
}