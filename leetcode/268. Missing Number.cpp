#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    //         int a = 0, b = 0;

    //         for(int i = 0; i <= nums.size(); i++){
    //             a = a ^ i;
    //             if(i < nums.size())
    //                 b = b ^ nums[i];
    //         }
    //         return a ^ b;
    int a = 0, b = 0;

    a = (nums.size() * (nums.size() + 1)) / 2;
    for (int i = 0; i < nums.size(); i++)
        b += nums[i];

    return a - b;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (auto &i : arr)
        cin >> i;

    cout <<missingNumber(arr)<<endl;
}