#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct node{
	int roll;
	char name[20];
	struct node *link;
};
struct node * HEAD;
void createLinkedList();
void dsp();

main()
{
	createLinkedList();
	dsp();
}
void createLinkedList()
{
	struct node *p,*q;
	char x[5];
	int count=2;
	int data;
	char na[20];
	HEAD=(struct node*)malloc(sizeof(struct node));
	p=HEAD;
	printf("1. Enter roll and name :");
	scanf("%d %[^\n]s",&data,na);
	p->roll=data;
	strcpy(p->name,na);
	p->link=NULL;
	while(1)
	{
		printf("Do you want to continue (Y/N):");
		scanf("%s",x);
		if(strcmp(x,"N")==0)
			break;
		q=(struct node *)malloc(sizeof(struct node));
		printf("%d. Enter roll and name :",count);
		scanf("%d %[^\n]s",&data,na);
		q->roll=data;
		strcpy(q->name,na);
		q->link=NULL;
		p->link=q;
		p=p->link;
		count++;
	}
	p->link=NULL;
}
void dsp()
{
	if(HEAD==NULL)
		printf("\nList is empty.\n");
	else
	{
		struct node *p=HEAD;
		while(p!=NULL)
		{
			printf(" Roll :%d\t Name :%s\n",p->name,p->roll);
			p=p->link;
		}
	}
}
