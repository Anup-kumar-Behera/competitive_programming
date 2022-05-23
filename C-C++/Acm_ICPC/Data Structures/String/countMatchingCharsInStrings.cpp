#include<bits/stdc++.h>

using namespace std;

int countCharacters(string s1,string s2)
{
	int c = 0,j = 0,i = 0;
	
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	
	int m = s1.length();
	int n = s2.length();
	
	while(i < m)
	{
		while(j < n)
		{
			if(s1[i] == s2[j])
				c += 1;
			continue;
			j += 1;
		}
		i += 1;
	}
	
	return c;
}

int main()
{
	string s1,s2;
	cout<<"Enter two strings: ";
	cin>>s1>>s2;
	
	int c = countCharacters(s1,s2);
	cout<<c<<endl;
	return 0;
}
