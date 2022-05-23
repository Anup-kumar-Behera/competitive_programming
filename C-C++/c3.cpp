#include<iostream>
using namespace std;
int sq(int );
int cube(int );

int main()
{
	int n;
	cout<<"Enter an integer n: ";
	cin>>n;
	int square=sq(n);
	int cu=cube(n);
	cout<<"square of n is:"<<square<<endl;
	cout<<"cube of n is:"<<cu<<endl;
	return 0;
}
int sq(int n)
{
	return n*n;
}
int cube(int n)
{
	return n*n*n;
}
