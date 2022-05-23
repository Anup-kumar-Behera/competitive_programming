#include<stdio.h>

struct student{
	int roll;
	char name[20];
	int mark;
};

main()
{
	struct student p[3];
	int i;
	for(i=0;i<3;i++)
	{
		scanf("%d",&p[i].roll);
		scanf("%[^\n]s",p[i].name);
		scanf("%d",&p[i].mark);
	}
	for(i=0;i<3;i++)
	{
		printf("\nRoll no:- ",p[i].roll);
		printf("\nName :- ",p[i].name);
		printf("\nMark :- ",p[i].mark);
	}
	
}
