#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct node{
	int roll;
	char name[20];
	struct node *link;
};
void traverse(struct node *);
main()
{
	struct stud *head=NULL,*p,*q;
	
	char x[2];
	while(1)
	{
		printf("Do you want to continue (Y/N): ");
		scanf("%s",x);
		if(strcpy(x,"N")==0)
			break;
		else
		{
			
			p=(struct node *)malloc(sizeof(struct node));
			q=(struct node *)malloc(sizeof(struct node));
			printf("\nEnter  roll :");
			scanf("%d",&p->roll);
			printf("Enter name :");
			scanf("%s",p->name);
			p->link=q;
			p=q;
		}
	}
	p->link=NULL;
	traverse(p);
}
void traverse(struct node * p)
{
	while(p!=NULL)
	{
		prinf("Roll :%d\t Name :%s\n",p->roll,p->name);
		p=p->link;
	}
}
