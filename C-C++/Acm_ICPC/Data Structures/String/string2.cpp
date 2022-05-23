//Count of sub-strings with equal consecutive 0’s and 1’s

#include<bits/stdc++.h>

using namespace std;

int countSubString(string s,int n)
{
	int ans = 0,i = 0;
	
	while(i < n)
	{
		int cnt0 = 0,cnt1 = 0;
		
		if(s[i] == '0' )
		{
			while(i < n && s[i] == '0')
			{
				cnt0++;
				i++;
			}
			
			int j = i;
			
			while(j < n && s[j] == '1')
			{
				cnt1++;
				j++;
			}
		}
		else
		{
			while(i < n && s[i] == '1')
			{
				cnt1++;
				i++;
			}
			int j = i;
			
			while(j < n && s[j] == '0')
			{
				cnt0++;
				j++;
			}
		}
		ans += min(cnt0,cnt1);
	}
	return ans;
}

int main()
{
	string s;
	cout<<"Enter a string of 0's and 1's : ";
	cin>>s;
	
	int l = s.length();
	
	int k = countSubString(s,l);
	cout<<endl<<k;
	
	return 0;
}
