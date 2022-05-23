#include"stdio.h"
#include"stdlib.h"

struct node{
	int roll;
	char name[20]	;
	struct node * link; 
};
struct node * createLinkList();
main()
{
	struct node * b;
	b=createLinkList();
}
struct node * createLinkList()
{
	struct node *p,*q,*temp;
	p=(struct node *)malloc(sizeof(struct node));
	temp=p;
	char x[5];
	printf("Enter roll :");
	scanf("%d",&p->roll);
	printf("Enter name :");
	scanf("%s",p->name);
	while(1)
	{
		printf("Do you wnat to continue (Y/N) :");
		scanf("%s",x);
		if(strcmp(x,"N")==0)
			break;
		q=(struct node*)malloc(sizeof(struct node));
		p->link=q;
		p=q;
		printf("Enter roll: ");
		scanf("%d",&p->roll);
		printf("Enter name:");
		scanf("%s",p->name);
	}
	p->link=0;
	return temp;
}
