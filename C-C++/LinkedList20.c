#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int roll;
	char name[20];
	struct node *link;
}node;
node *head;
int i=0;
void createLinkedList();
void display();
void mid();

int main()
{
	int c;
	printf("Enter the following choices to perform the respective actions:\n\n");
	printf("Enter '1' to create Linked List.\n");
	printf("Enter '2' to display List.\n");
	printf("Enter '3' to quit.\n");
	printf("Enter '4' to dsp mid values.\n\n\n");
	
	while(c!=3)
	{
		printf("\n--------------------------------------------------\n");
		printf("Enter choice: ");
		scanf("%d",&c);
		switch(c)	
		{
			case 1:printf("\n-------------------------------------------------\n");
			 	   createLinkedList();
			 	   break;
			case 2:printf("\n-------------------------------------------------\n");
				   display();
				   break;
			case 3:printf("\n-------------------------------------------------\n");
				   break;
			case 4:printf("\n-------------------------------------------------\n");
				   mid();
				   break;
		}
	}
	return 0;
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
				printf("\nMemory can not be alloctaed.\n");
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
void display()
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
void mid()
{
	node *p=head,*loc;
	int i=0,j=0;
	while(p!=NULL)
	{
		p=p->link;
		i++;
	}
	int k=(i/2);
	while(p!=NULL)
	{
		if(j==k)
		{
			loc=p;
			break;
		}
		else
		{
			p=p->link;
			j++;
		}
	}
	printf("Mid values are:\n");
	printf("Roll: %d\t Name: %s\n",loc->link->roll,loc->link->name);
}
