#include<stdio.h>
void TOWER(int ,char [],char [],char []);

main()
{
	int n;
	printf("Enter number of discs to be transferred: ");
	scanf("%d",&n);
	
	if(n<1)
		printf("\nIncorrect value.");
	else
	{
		printf("Following moves are required for %d discs.\n",n);
		TOWER(n,"BEG","AUX","END");
	}
}
void TOWER(int n,char A[5],char B[5],char C[5])
{
	if(n==1)
	{
		printf("%s -> %s\t",A,C);
		return ;
	}
	TOWER(n-1,A,C,B);
	printf("%s -> %s\t",A,C);
	TOWER(n-1,B,A,C);
	return ;
}
