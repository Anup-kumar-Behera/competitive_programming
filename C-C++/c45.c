#include"stdio.h"
#include"string.h"
main()
{
	char a[20]="abcaad";
	printf("Enter a string: ");
	scanf("%s",a);
	int i=strlen(a);
	int j=i/2,n=0,m=0,k,l;
	char b[]="abcdefghijklmnopqrstuvwxyz";
	char c[m];
	for(k=0;k<strlen(b);k++)
	{
		for(l=0;l<strlen(a);l++)
		{
			if(strcmp(b[k],a[l])==0)
			{
				m++;
				strcpy(c[m],a[l]);
			}
		}
	}
	printf("%s",c);
}
