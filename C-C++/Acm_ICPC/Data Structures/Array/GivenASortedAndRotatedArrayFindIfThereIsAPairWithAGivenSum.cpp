#include<bits/stdc++.h>
//#include<unordered_set>;
using namespace std;

/*void pair(int *arr,int n,int sum)
{
	unordered_set<int> s;
	
	for(int i = 0;i < n;i++)
	{
		if(s.find(sum-arr[i]) != s.end())
			cout<<"The pair with sum "<<sum<<" are "<<arr[i]<<" and "<<sum-arr[i]<,endl;
		s.insert(arr[i]);
	}
}*/

void printPairs(int arr[], int arr_size, int sum) 
{ 
    typedef unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) { 
        int temp = sum - arr[i]; 
  
        if (s.find(temp) != s.end()) 
            cout << "Pair with given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << endl; 
  
        s.insert(arr[i]); 
    } 
}

int main()
{
	int arr[] = {0,-1,2,-3,1};
	int n = 5,sum = -2;
	//pair(arr,n,sum);
	printPairs(arr,n,sum);
	
	return 0;
}
