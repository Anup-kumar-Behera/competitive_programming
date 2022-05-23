#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;

node *HEAD;
void createLinkedList();
void dsp();
main()
{
	createLinkedList();
	dsp();
}
void createLinkedList()
{
	node *p,*q;
	HEAD=(node *)malloc(sizeof(node));
	p=HEAD;
	int data;
	char n[20];
	char x[5];
	printf("Enter name and roll: ");
	scanf("%[^\n]s %d",n,&data);
	p->roll=data;
	strcpy(p->name,n);
	p->link=NULL;
	while(1)
	{
		printf("Do you want to continue (Y/N):");
		scanf("%s",x);
		if(strcpy(x,"N")==0)
			break;
		else{
		q=(node *)malloc(sizeof(node));
		p->link=q;
		p=q;
		printf("Enter name and roll: ");
		scanf("%[^\n]s %d",n,&data);
		q->roll=data;
		strcpy(q->name,n);
	}
	p->link=NULL;}
}
void dsp()
{
	node *p;
	p=HEAD;
	while(p!=NULL)
	{
		printf("roll: %d \t name: %s\n",p->roll,p->name);
		p=p->link;
	}
}
