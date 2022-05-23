#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> g1;
	
	for(int i = 0; i < 10;i++)
		g1.push_back(i);
	int i;
	for(i = 0;i < 10;i++)
		cout<<*g1()<<" ";
		
	
	return 0;
}
