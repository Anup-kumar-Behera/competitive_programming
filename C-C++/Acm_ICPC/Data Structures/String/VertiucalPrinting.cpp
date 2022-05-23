#include<bits/stdc++.h>
#include<cstring>

using namespace std;

void verticalPrint(string s)
{
	int l = s.length();
	int j = 0,i = 0,k,c = 1,temp = 0;
	
	for(i = 0;i < l;i++)
	{
		if(s[i] == ' ')
			c += 1;
	}
	int ar[c];
	c = 0;
	for(i = 0;i < l;i++)
	{
		c += 1;
		if(s[i] == 0)
			c = 0;
		k = max(ar[j],ar[j+1]);
		if(s[i+1] == ' ')
		{
			ar[j] = c;
			j++;
		}
			
	}
	cout<<k<<endl;
}

int main()
{
	string s;
	cout<<"Enter a string:";
	cin>>s;
	
	verticalPrint(s);
	
	return 0;
}
