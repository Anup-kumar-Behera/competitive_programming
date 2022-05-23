#include<stdio.h>
struct student{
	int roll;
	char name[20];
	int mark;
};
void sort(struct student [],int );
main()
{
	struct student p[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("Enter roll :");
		scanf("%d",&p[i].roll);
		printf("Enter name:");
		scanf("%s",p[i].name);
		printf("Enter mark:");
		scanf("%d",&p[i].mark);
	}
	sort(p,5);
	for(i=0;i<5;i++)
	{
		printf("%d %s %d \n",p[i].roll,p[i].name,p[i].mark);
	}
}
void sort(struct  student p[],int k)
{
	int i,j;
	struct student temp;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(p[i].mark>p[j].mark)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
