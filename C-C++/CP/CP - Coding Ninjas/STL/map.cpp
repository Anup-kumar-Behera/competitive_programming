#include<iostream>
#include<map>
using namespace std;

int main(){
	
	int arr[] = {1,2,3,4,5,6,5};
	
	map<int, int>  mp;
	
	for(int i = 0; i < 7; i++){
		mp[arr[i]]++;
	}
	map<int, int>::iterator it;
	//mp.erase(9);
	for(it = mp.begin(); it != mp.end(); it++)
		cout<<it->first<<" "<<it->second<<endl;
	it = mp.find(5);
	cout<<it->first<<" : "<<it->second<<endl;
}
