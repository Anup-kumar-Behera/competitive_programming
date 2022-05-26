#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n){
    vector<int> ans;

    if (n % 2 == 1)
        ans.push_back(0);
    for (int i = n; i > (n - (n / 2)); i--)
    {
        ans.push_back(i);
        ans.insert(ans.begin(), -i);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    vector<int> ans = sumZero(n);

    for(auto x:ans)
        cout<<x<<" ";
        
}