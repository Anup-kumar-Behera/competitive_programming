#include"stdio.h"
#include"stdlib.h"
int pop();
void push(int );
int empty();
//int full();
 typedef struct node{
 	int data;
 	struct node *link;
 }node;
 node *head=NULL,*p=NULL,*q;
 
 main()
 {
 	int data,n;
 	do
 	{
 		printf("\n1 to push.\n");
 		printf("2 to pop.\n");
 		printf("0 to quit.\n");
 		printf("Enter choice: ");
 		scanf("%d",&n);
 		if(n==1)
 		{
 			/*if(full())
 			{
 				printf("Overflow.\n");
 				continue;
			}*/
			printf("Enter data: ");
			scanf("%d",&data);
			push(data);
		}
		else if(n==2)
		{
			if(empty())
			{
				printf("Underflow.\n");
				continue;
			}
			data=pop();
			printf("%d",data);
		}
	}while(n!=0);
 }
 void push(int data)
 {
 	if(head==NULL)
 	{
 		head=(node *)malloc(sizeof(node));
 		p=head;
 		p->data=data;
 		p->link=NULL;
	}
	q=(node *)malloc(sizeof(node));
	q->data=data;
	p->link=q;
	q->link=NULL;
	p=p->link;
 }
 int pop()
 {
 	int k=head->data;
 	node *r=head;
 	head=head->link;
 	free(r);
 	return k;
 }
 int empty()
 {
 	if(head==NULL)
 		return 1;
 	else 
 		return 0;
 }
/* int full()
 {
 	if(q==NULL)
 		return 1;
 	else
 		return 0;
 }*/
