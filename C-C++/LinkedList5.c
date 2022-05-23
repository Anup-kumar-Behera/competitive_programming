#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;
node * HEAD;
void createLinkedList();
void dsp();

main()
{
	createLinkedList();
	dsp();
}
void createLinkedList()
{
	node *p,*q,*temp;
	int r;
	char n[20];
	HEAD=(node *)malloc(sizeof(node));
	printf("Enter name and Roll :");
	scanf("%[^\n]s %d",n,&r);
	HEAD->roll=r;
	strcpy(HEAD->name,n);
	HEAD->link=NULL;
	p=HEAD;
	char x[5];
	while(1)
	{
		printf("Do you want to continue (Y/N):");
		scanf("%s",x);
		if(strcpy(x,"N")==0)
			break;
		else
		{
			q=(node *)malloc(sizeof(node));
			printf("Enter name and Roll :");
			scanf("%[^\n]s %d",n,&r);
			HEAD->roll=r;
			strcpy(HEAD->name,n);
			q->link=NULL;
			p->link=q;
			p=q;
		}
	p->link=NULL;
	}
}
void dsp()
{
	node *p=HEAD;
	while(p!=NULL)
	{
		printf("Roll: %d\t Name: %s\n",p->roll,p->name);
		p=p->link;
	}
}
