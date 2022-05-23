#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int data;
	struct node *next;
}node;
node *head;
void createList();
void dsp();
void del();
void rev();

main()
{
	int a=100;
	printf("Enter the following choices: \n");
	printf("0 to exit.\n");
	printf("1 to createList.\n");
	printf("2 to dispaly list.\n");
	printf("3 to reverse List.\n");
	printf("4 to delete all occurances of the item form the list.\n\n");
	
	while(a!=0)
	{
		printf("Enter choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 0: break;
			
			case 1: createList();
					break;
			case 2: dsp();
					break;
			case 3: rev();
					break;
			case 4: del();
					break;
		}	
	}
}
void createList()
{
	node *p,*q;
	head=(node *)malloc(sizeof(node));
	p=head;
	int d,i=2;
	char x[5];
	if(p==NULL)
		printf("Memory can not be allocated.\n");
	else
	{
		printf("1. Enter data: ");
		scanf("%d",&d);
		p->data=d;
		p->next=NULL;
		while(1)
		{
			printf("Do you want to continue: ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("Memory can not be allocated.\n");
			else
			{
				printf("%d. Enter data: ",i);
				scanf("%d",&d);
				q->data=d;
				q->next=NULL;
				p->next=q;
				p=p->next;
				i++;
			}
		}
		p->next=NULL;
	}
}
void dsp()
{
	if(head==NULL)
		printf("List is empty.\n");
	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("Data: %d\n",p->data);
			p=p->next;
		}
	}
}
void rev()
{
	node *pre=NULL,*next=NULL,*p=head;
	while(head)
	{
		next=head->next;
		head->next=pre;
		pre=head;
		head=next;
	}
	while(pre!=NULL)
	{
		printf("Data: %d\n",pre->data);
		pre=pre->next;
	}
}
void del()
{
	node *p=head,*loc=NULL,*save=NULL;
	int item;
	printf("Enter item to delete: ");
	scanf("%d",&item);
	while(p!=NULL && p->data==item)
	{
		head=p->next;
		free(p);
		p=head;
	}
	while(p!=NULL)
	{
		while(p!=NULL && p->data!=item)
		{
			save=p;
			p=p->next;
		}
		save->next=p->next;
		free(p);
		p=save->next;
	}
}
