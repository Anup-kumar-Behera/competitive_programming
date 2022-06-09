#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int arr[m+n];
        
        int it = 0, i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                arr[it++] = nums1[i++];
            }else{
                arr[it++] = nums2[j++];
            }
        }
        
        while(i < m){
            arr[it++] = nums1[i++];
        }
        while(j < n){
            arr[it++] = nums2[j++];
        }
        for(i = 0; i < m+n; i++)
            nums1[i] = arr[i];
    }
};

int main(){
    int m, n;
    cin>>m>>n;

    vector<int> nums1(m+n, 0), nums2(n, 0);

    for(int i = 0; i < m; i++){
        int x;
        cin>>x;
        nums1[i] = x;
    }
    for(auto &i:nums2)  cin>>i;

    Solution s;
    s.merge(nums1, m, nums2, n);
}