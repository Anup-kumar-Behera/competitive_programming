#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;
node *head;
void createLinkedList();
void dsp();
void mid();

main()
{
	createLinkedList();
	dsp();
	mid();
}
void createLinkedList()
{
	node *p,*q;
	int data,i=2;
	char n[20],x[5];
	head=(node *)malloc(sizeof(node));
	p=head;
	if(p==NULL)
		printf("\nMemory can not be allocated.\n");
	else
	{
		printf("1. Enter roll and name: ");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->link=NULL;
		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("\nMemory can not be allocated.\n");
			else
			{
				printf("%d. Enter roll and name: ",i);
				scanf("%d %[^\n]s",&data,n);
				q->roll=data;
				strcpy(q->name,n);
				q->link=NULL;
				p->link=q;
				p=p->link;
				i++;
			}
		}
		p=p->link;
	}
}
void dsp()
{
	int i=0;
	if(head==NULL)
		printf("\nList is empty.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Roll: %d \t Name: %s\n",p->roll,p->name);
			p=p->link;
			i++;
		}
	}
	printf("\nNumber of nodes: %d\n",i);
}
void mid()
{
	int i=0,j=0,d;
	char cp[20];
	while(head!=NULL)
	{
		head=head->link;
		i++;
	}
	while(head!=NULL)
	{
		if(j==(i/2))
		{
			d=head->roll;
			strcpy(cp,head->name);
			break;
		}
		else
		{
			head=head->link;
			j++;
		}
	}
	printf("Mind values :-\n");
	printf("Roll: %d\t Name: %s\n",d,cp);
}
