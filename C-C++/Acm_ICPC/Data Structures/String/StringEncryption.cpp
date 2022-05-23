#include<bits/stdc++.h>
using namespace std;

string encryption(string s)
{
	int l = s.length();
	int b = ceil(sqrt(l));
	int a = floor(sqrt(l));
	
	string encrypted;
	if(b * a < l)
	{
		if(min(a,b) == a)
			a = a+1;
		else
			b = b+1;
	}
	char arr[a][b];
	memset(arr," ",sizeof(arr));
	int k = 0;
	for(int j = 0;j < a;j++)
		for(int i = 0;i < b;i++)
		{
			if(k < l)
				arr[j][i] = s[k];
			k++;
		}
	
	for(int j = 0;j < b;j++)
		for(int i = 0;i < a;i++)
		{
			encrypted = encrypted + arr[j][i];
		}
	return encrypted;
}
int main()
{
	char s[20];
	cout<<"Enter a string: ";
	cin>>s;
	
	string  e = encryption(s);
	cout<<"Encrypted string is:"<<e<<endl;
	
	
	return 0;
}
