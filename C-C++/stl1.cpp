#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	vector<int>::iterator itr = v.begin();
	
	cout<<*(itr+1)<<endl;
	cout<<"size => "<<v.size()<<endl;
	int i;
	for(i = 0;i<v.size();i++)
		cout<<i+1<<".val => "<<*(itr+i)<<endl;
	
	return 0;
}
