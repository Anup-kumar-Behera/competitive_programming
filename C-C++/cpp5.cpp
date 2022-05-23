#include<bits/stdc++.h>
using namespace std;

int reverse(int n)
{
	int a,s = 0;
	while(n > 0)
	{
		a = n%10;
		s = s*10+ a;
		n /= 10;
	}
	return s;
}
int main()
{	
	int n;
	cout<<"Enter an integer: ";
	cin>>n;
	
	int k = reverse(n);
	cout<<endl<<"Reversed integer is: "<<k<<endl;
	
	double p = 78.32;
	cout<<p<<endl;
	cout<<(int)p;

	return 0;
}
