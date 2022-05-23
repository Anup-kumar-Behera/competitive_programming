//The time complexity of KMP algorithm is O(n) in the worst case.


#include<stdio.h>
#include<string.h>


void computeLPSArray(char *pat,int lps[],int m)
{
	int len = 0;
	lps[0] = 0;
	
	int i = 1;
	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			len ++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KPMSearch(char *txt,char *pat)
{
	int m = strlen(pat);
	int n = strlen(txt);
	
	int lps[m];
	
	computeLPSArray(pat,lps,m);
	
	int i = 0,j = 0;
	
	while(i < n)
	{
		if(pat[j] == txt[i])
		{
			i ++;
			j++;
		}
		if(j == m)
		{
			printf("Pattern found at index : %d\n",i-j);
			j = lps[j-1];
		}
		else if(i < n && pat[j] != txt[i])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i ++;
		}
	}
}

main()
{
	char str[20];
	char pat[10];
	
	printf("Enter text where pattern to be search: ");
	scanf("%s",str);
	printf("\nEnter pattern to be searched: ");
	scanf("%s",pat);
	
	KPMSearch(str,pat);
}
