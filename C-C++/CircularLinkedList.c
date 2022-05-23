#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct cllnode{
	int data;
	struct cllnode *link;
}cllnode;
cllnode *head;
void createCll();
void traverse();

main()
{
	createCll();
	printf("\n---------------------------------------------------------------------------\n");
	traverse();
}
void createCll()
{
	cllnode *p,*q;
	int data,i=2;
	head=(cllnode *)malloc(sizeof(cllnode));
	p=head;
	char x[5];
	if(p==NULL)
		printf("\nMemory can not be allocated.\n");\
	else
	{
		printf("1. enter data: ");
		scanf("%d",&data);
		p->data=data;
		p->link=head;
		while(1)
		{
			printf("Do you want to continue (Y/N): ");
			scanf("%s",x);
			if(strcmp(x,"N")==0)
					break;
			else
			{
				q=(cllnode *)malloc(sizeof(cllnode));
				if(q==NULL)
					printf("\nMemory can not be allocated.\n");
				else
				{
					printf("%d. Enter data: ",i);
					scanf("%d",&data);
					q->data=data;
					q->link=head;
					p->link=q;
					p=p->link;
					i++;
				}
			}
		}
		p->link=head;
	}
}
void traverse()
{
	int n;
	if(head->link==head)
		printf("\nCircular Linked List is empty.\n");
	else
	{
		cllnode *p=head;
		do
		{
			printf("data: %d\n",p->data);
			p=p->link;
			n++;
		}while(p!=head);
	}
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("No of nodes : %d \n",n);
}
