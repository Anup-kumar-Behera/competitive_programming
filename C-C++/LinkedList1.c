#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int data;	
	struct node *link;
}node;

node * create(int n);
void dsp(node * );
main()
{
	int n;
	node * HEAD=NULL;
	printf("How many nodes : ");
	scanf("%d",&n);
	HEAD=create(n);
	dsp(HEAD);
}
node * create(n)
{
	int i=0;
	node * HEAD=NULL;
	node * TEMP=NULL;
	node * p=NULL;
	for(i=0;i<n;i++)
	{
		TEMP=(node *)malloc(sizeof(node));
		printf("\nEnter the data for node number %d : ",i+1);
		scanf("%d",&(TEMP->data));
		TEMP->link=NULL;
		
		if(HEAD==NULL)
		{
			HEAD=TEMP;
		}
		else
		{
			p=HEAD;
			while(p->link!=NULL)
				p=p->link;
			p->link=TEMP;
		}
	}
	return HEAD;
}
void dsp(node * HEAD)
{
	node *p=HEAD;
	while(p->link!=NULL)
	{
		printf("\t%d",p->data);
		p=p->link;
	}
}
