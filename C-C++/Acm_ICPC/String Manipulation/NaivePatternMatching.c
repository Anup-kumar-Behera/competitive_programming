//The number of comparisons in the worst case is O(m*(n-m+1)).
//The best case occurs when the first character of the pattern is not present in text at all.
//The number of comparisons in best case is O(n). 


#include<stdio.h>
#include<string.h>

void PatternMatch(char *str,char *pat)
{
	int n = strlen(str);
	int m = strlen(pat);
	
	int i = 0,j = 0;
	
	for(i = 0;i < n-m;i++)
	{
		for(j = 0;j < m;j++)
			if(str[i+j] != pat[j])
				break;
		if(j == m)
			printf("pattern found at index :%d \n",i);
			
	}
}
main()
{
	char str[30];
	char pat[10];
	
	printf("Enter a text where pattern to be searched: ");
	scanf("%s",str);
	
	printf("Enter pattern to be searched: ");
	scanf("%s",pat);
	
	PatternMatch(str,pat);
}
