#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;
node *head;
void createList();
void del();
void dsp();
void insert();
void search();

main()
{
	int n;
	do
	{
		printf("\n1 to createList.\n");
		printf("6 to display.\n");
		printf("2 to Insert in the list.\n");
		printf("3 to delete form the list.\n");
		printf("4 to search in the list.\n");
		printf("0 to quit.\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: createList();
					break;
			case 2: insert();
					break;
			case 3: del();
					break;
			case 4: search();
					break;
			case 6: dsp();
					break;
		}
	}while(n!=0);
}
void createList()
{
	node *p,*q;
	char x[5],n[20];
	int data,i=2;
	
	head=(node *)malloc(sizeof(node));
	p=head;
	if(p==NULL)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter roll and name : ");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		p->link=NULL;
		while(1)
		{
			printf("Do you want to contnue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("Overflow.\n");
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
	}
}
void dsp()
{
	int i=1;
	if(head==NULL)
		printf("Underflow.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("%d. roll= %d \t name= %s\n",i,p->roll,p->name);
			p=p->link;
			i++;
		}
	}
}
void del()
{
	node *p=head,*loc=NULL,*save=NULL;
	int data;
	printf("Enter roll number to delete: ")	;
	scanf("%d",&data);
	if(p->roll==data)
	{
		head=p->link;
		free(p);
		p=head;
	}
	else
	{
		while(p!=NULL)
		{
			if(p->roll==data)
			{
				loc=p;
				break;
			}
			else
			{
				save=p;
				p=p->link;
			}
		}
		if(p==NULL)
			loc=NULL;
		if(loc==NULL)
			printf("Item to be deleted not found in the list.\n");
		else
		{
			save->link=loc->link;
			free(loc);
		}
	}
}
void insert()
{
	node *p=head,*newNode,*loc;
	char n[20];
	int data,key;
	newNode=(node *)malloc(sizeof(node));
	if(newNode==NULL)
		printf("Overflow.\n");
	else
	{
		printf("Enter roll after which you want to insert node: ");
		scanf("%d",&key);
		printf("Enter roll and name: ");
		scanf("%d %[^\n]s",&data,n);
		newNode->roll=data;
		strcpy(newNode->name,n);
		while(p!=NULL)
		{
			if(p->roll==key)
			{
				loc=p;
				break;
			}
			else
			{
				p=p->link;
			}
		}
		if(p==NULL)
			loc=NULL;
		if(loc==NULL)
		{
			newNode->link=head;
			head=newNode;
		}
		else
		{
			newNode->link=loc->link;
			loc->link=newNode;
		}
	}
}
void search()
{
	node *p=head,*loc=NULL;
	int key;
	printf("Enter roll to search in the list: ");
	scanf("%d",&key);
	while(p!=NULL)
	{
		if(p->roll==key)
		{
			loc=p;
			break;
		}
		else
		{
			p=p->link;
		}
	}
	if(p==NULL)
		loc=NULL;
	if(loc==NULL)
		printf("Search Unsuccessful.\n");
	else
	{
		printf("Roll: %d\tName: %s.\n",loc->roll,loc->name);
	}
}
