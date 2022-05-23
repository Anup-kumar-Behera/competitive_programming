#include"iostream"
using namespace std;
int IsLeapYear(int );

int main()
{
	int year;
	cout<<"Enter a year AD, for example, 1997."<<endl;
	cin>>year;
	if(IsLeapYear(year))
		cout<<year<<" is a leap year."<<endl;
	else
		cout<<year<<" is not a leap year."<<endl;
	return 0;
}
int IsLeapYear(int year)
{
	if(year%4!=0)
		return false;
	else if(year%100 !=0)
		return true;
	else if(year%400!=0)
		return false;
	else
		return true;
}
