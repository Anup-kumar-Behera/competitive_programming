#include"stdio.h"
#include<conio.h>

void TOWER(int ,char [],char [],char []);

main()
{
	int N;
	printf("Enter number of discs to be transferred: ");
	scanf("%d",&N);
	
	if(N<1)
	{
		printf("Incorrect Value.\n");
	}
	else
	{
		printf("Following moves are reqiured: \n");
		TOWER(N,"BEG","AUX","END");
	}
}
void TOWER(int num,char A[5],char B[5],char C[5])
{
	if(num==1)
	{
		printf("%s -> %s\t",A,C);
		return ;
	}
	TOWER(num-1,A,C,B);
	printf("%s -> %s\t",A,C);
	TOWER(num-1,B,A,C);
	return ;
}
