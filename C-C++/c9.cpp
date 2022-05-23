#include"iostream"
#include"math.h"
using namespace std;

main()
{
	cout<<"Program to convert Decimal to Binary."<<endl;
	int n,i=-1;
	cout<<"Enter an integer: ";
	cin>>n;
	int s=log(n)/log(2)+1;
	int x[s];
	while(n>0)
	{
		i++;
		x[i]=n%2;
		n/=2;
	}
	while(i>=0)
	{
		cout<<x[i];
		i--;
	}
}
