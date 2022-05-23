#include<stdio.h>

struct student{
	int roll;
	int name[20];
	int mark;
};

main()
{
	struct student p[5];
	int i;
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&p[i].roll);
		scanf("%[^\n]s",p[i].name);
		scanf("%d",&p[i].mark);
	}
	for(i=0;i<5;i++)
	{
		printf("%d	,%s	,%d	\n",p[i].roll,p[i].name,p[i].mark);
	}
}
