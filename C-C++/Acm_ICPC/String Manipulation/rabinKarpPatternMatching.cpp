//The average and best case running time of the Rabin-Karp algorithm is O(n+m).
//Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[].
//its worst-case time is O(nm).


#include<bits/stdc++.h>
#define d 256
using namespace std;

void rabinKarp(char *txt,char *pat,int q)
{
	int m = strlen(pat);
	int n = strlen(txt);
	
	int i,j;
	int p = 0;
	int t = 0;
	int h = 1;
	
	for(i = 0;i < m-1;i++)
		h = (h * d) % q;
	
	for(i = 0;i < m;i++)
	{
		p = (p * d+pat[i]) % q;
		t = (t * d+txt[i]) % q;
	}
	
	for(i = 0;i <= n-m;i++)
	{
		if(p == t)
		{
			for(j = 0;j < m;j++)
				if(txt[i+j] != pat[j])
					break;
			if(j == m)
				cout<<"Pattern found at index :"<<i<<endl;
		}
		 
		if(i < n-m) 
		{
			t = (d*(t - txt[i] * h)+txt[i+m]) % q;
			
			if(t < 0)
				t = t + q;
		}
	}
}

int main()
{
	char txt[30];
	char pat[20];
	int q;
	
	cout<<"Enter txt where pattern to be searched: ";
	cin>>txt;
	
	cout<<endl<<"Enter pattern to be searched: ";
	cin>>pat;
	
	cout<<endl<<"Enter a prime number: ";
	cin>>q;
	
	rabinKarp(txt,pat,q);
	
	return 0;
}
