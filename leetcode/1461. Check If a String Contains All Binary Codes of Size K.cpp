#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k)
{
    if (k > s.length())
        return false;

    int c = 0;
    int l = 0, r = pow(2, k) - 1;
    unordered_set<int> st;

    for (int i = 0; i <= s.length() - k; i++)
    {
        string tmp = s.substr(i, k);
        st.insert(stoi(tmp, 0, 2));
    }

    return (st.size() == r + 1);
}

int main()
{
    string s; // Binary string
    cin >> s;
    int k;
    cin >> k;
    if(hasAllCodes(s, k))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

}