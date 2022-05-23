#include"iostream"
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter two integers a and b: ";
	cin>>a;
	cin>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"a ="<<a<<"b ="<<b;
	cout<<endl;
	return 0;
}
