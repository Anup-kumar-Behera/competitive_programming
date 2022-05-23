#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int arr[] = {1,3,2,4,5,7,6};
	sort(arr, arr+7);	//increasing sort
	for(int i = 0; i < 7; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	sort(arr, arr+7, greater<int>());//decreasing sort
	for(int i = 0; i < 7; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
