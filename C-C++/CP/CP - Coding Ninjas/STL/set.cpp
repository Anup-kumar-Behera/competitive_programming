#include<set>
#include<iostream>
using namespace std;

int main(){
	
	set<int> s;
	int arr[] = {1,2,3,4,5,5,6,7,8,9,1,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i < n; i++)
		s.insert(arr[i]);
	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	
	if(s.find(6) == s.end())
		cout<<"Element not found"<<endl;
	else
		cout<<"Element found"<<endl;
}
