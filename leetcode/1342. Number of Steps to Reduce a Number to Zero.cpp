#include <bits/stdc++.h>
using namespace std;

int numberOfSteps(int num)
{
    int c = 0;

    while (num != 0)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num -= 1;
        c++;
    }
    return c;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout <<numberOfSteps(n)<<endl;
    }
}