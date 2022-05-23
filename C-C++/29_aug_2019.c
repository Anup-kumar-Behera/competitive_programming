#include"stdio.h"
#include"stdlib.h"
#include"string.h"
 typedef struct node{
 	int data;
 	struct node *link;
 }node;
 node *head;
 void createlist();
 void dsp();
 void rev();
 void del();
 
 main()
 {
 	int a=100;
 	printf("Enter 1 to createlist.\n");
 	printf("Enter 2 to display.\n");
 	printf("Enter 3 to display.\n");
 	printf("Enter 4 to delete.\n");
 	printf("Enter 0 to stop\n\n");
 	while(a!=0)
 	{
 		printf("Enter choice: ");
 		scanf("%d",&a);
 		switch(a)
 		{
 			case 0: break;
 			
 			case 1: createlist();
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
 void createlist()
 {
 	node *p,*q;
 	head=(node *)malloc(sizeof(node));
 	p=head;
 	int d;
 	char x[5];
 	int i=2;
 	if(p==NULL)
 		printf("Memory can not be allocated.\n");
 	else
 	{
 		printf("1. Enter data: ");
 		scanf("%d",&d);
 		p->data=d;
		p->link=NULL;
		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("Memoy can not be allocated.\n");
			else
			{
				printf("%d. Enter data: ",i);
				scanf("%d",&d);
				q->data=d;
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
 		printf("List is empty.\n");
 	else
	{
		node *p=head;
		while(p!=NULL)
		{
			printf("data: %d \n",p->data);
			p=p->link;
		}
	} 	
 }
 void rev()
 {
 	node *pre=NULL,*next,*p;
 	p=head;
 	while(p!=NULL)
 	{
 		next=p->link;
 		p->link=pre;
 		pre=p;
 		p=next;
	}
	head=pre;
	while(pre!=NULL)
	{
		printf("data: %d \n",pre->data);
		pre=pre->link;
	}
 }
 void del()
 {
 	int item;
 	printf("Enter item to delete: ");
 	scanf("%d",&item);
 	node *loc,*save,*p=head;
 	if(p->data==item)
 	{
 		head=p->link;
 		free(p);
 		p=head;
	 }
	while(p!=NULL) 
	{
		if(p->data==item)	
		{
			loc=p;
			p=loc->link;
		}
		save->link=loc->link;
		free(loc);
		save=p;
		p=p->link;
	}
}
