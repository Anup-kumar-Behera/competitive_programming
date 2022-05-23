#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct node{
	int data;
	struct node *link;
}node;

node *head;
 void createList();
 void dsp();
 
 main()
 {
 	createList();
 	dsp();
 }
 void createList()
 {
 	node *p,*q,*r;
 	int d,i=2;
 	char x[5];
 	head=(node *)malloc(sizeof(node));
 	p=(node *)malloc(sizeof(node));
 	head->link=p;
 	r=p;
 	if(head==NULL)
		printf("Overflow.\n");
	if(r==NULL)
		printf("Overflow.\n");
	else
	{
		printf("1. Enter data: ");
		scanf("%d",&d);
		r->data=d;
		r->link=head;
		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
				break;
			q=(node *)malloc(sizeof(node));
			if(q==NULL)
				printf("Overflow.\n");
			else		
			{
				printf("%d. Enter data: ",i);
				scanf("%s",x);
				q->data=d;
				q->link=NULL;
				r->link=q;
				r=r->link;
				i++;
			}
		}
		r->link=head;
	}
 }
 void dsp()
 {
 	if(head->link==head)
 		printf("List is empty.\n");
 	else
 	{
 		node *p=head->link;
 		while(p!=head)
 		{
 			printf("data: %d\n",p->data);
 			p=p->link;
		}
	}
 }
