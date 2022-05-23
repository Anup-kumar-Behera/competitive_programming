#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> l;
	l.push_back(10);
	l.push_back(50);
	l.push_back(37);
	l.push_back(90);
	
	sort(l.begin(),l.end());
	vector<int>::iterator itr=l.begin();
	//auto itr = v.begin();
	
	for(; itr != l.end();itr++)
		cout<<"Value: "<<*itr<<endl;
	
	
	return 0;
}
