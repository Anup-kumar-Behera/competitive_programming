#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;
node * head;
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
	head=(node *)malloc(sizeof(node));
	p=head;
	int data,i=2;
	char n[20];
	char x[5];
	if(p==NULL)
		printf("\nOverflow (Memory can not be allocated).\n");
	else
	{
		printf("1. Enter roll and name:");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->link=NULL;
		while(1)
		{
			printf("do you want to cotinue (Y/N):");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			printf("%d. Enter roll and name:",i);
			scanf("%d %[^\n]s",&data,n);
			q->roll=data;
			strcpy(q->name,n);
			q->link=NULL;
			p->link=q;
			p=p->link;
			i++;
		}
		p->link=NULL;
	}
}
void dsp()
{
	if(head==NULL)
		printf("\nUnderflow (List is empty).\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("roll: %d \t name: %s \n",p->roll,p->name);
			p=p->link;
		}
	}
}

