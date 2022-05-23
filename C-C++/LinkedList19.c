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
void insert();

main()
{
	createLinkedList();
	dsp();
	insert();
	dsp();
}
void createLinkedList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=head;
	int data,i=2;
	char n[20],x[5];
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
		p->link=NULL;
	}
}
void dsp()
{
	if(head==NULL)
		printf("\nList is empty.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Roll: %d \t Name: %s\n",p->roll,p->name);
			p=p->link;
		}
	}
}
void insert()
{
	int n,data;
	char na[20];
	node *p=head,*save,*loc;
	int i=0;
	printf("Enter the postion at which a new node will be inserted (0 for 1st node ): ");
	scanf("%d",&n);
	node *new;
	new=(node *)malloc(sizeof(node));
	if(new==NULL)
		printf("\nMemory can not be allocated.\n");
	else
	{
		printf("Enter the new node details\n");
		printf("Enter roll and name: ");
		scanf("%d %[^\n]s",&data,na);
		new->roll=data;
		strcpy(new->name,na);
		new->link=NULL;
	}
	if(n==0)
	{
		new->link=head;
		head=new;
	}
	else
	{
		while(p!=NULL)
		{
			if(i==n)
			{
				loc=p;
				break;
			}
			else
			{
				save=p;
				p=p->link;
				i++;
			}
		}
		new->link=save->link;
		save->link=new;
	}
		
}
