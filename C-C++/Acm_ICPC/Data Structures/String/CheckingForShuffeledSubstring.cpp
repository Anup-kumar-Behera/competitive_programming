#include<bits/stdc++.h>

using namespace std;

string sortString(string str)
{
	int n = str.length();
	sort(str.begin(),str.end());
	return str;
}

bool checkString(string str1,string str2)
{
	int n = str1.length();
	int m = str2.length();
	string YES,NO;
	
	if(n > m)
		return false;
	else
	{	
		str1 = sortString(str1);
		char temp[n];
		memset(temp," ",sizeof(temp));
		int k = 0;
		while(k < m)
		{
			for(int i = k;i < n;i++)
				temp[i] = str2[i];
			temp = sortString(temp);
	
			if(str1 == temp)
			{
				return true;
				break;
			}	
			k++;
		}
		return false;
	}
}

int main()
{
	string str1,str2;
	
	cout<<"Enter two strings: ";
	cin>>str1>>str2;
	
	bool check = checkString(str1,str2);
	
	cout<<"Is the given string is shuffeled substring of another string: ";
	if(check)
		cout<<"Yes"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
