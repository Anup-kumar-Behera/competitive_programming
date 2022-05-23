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
  void insert(int );
  
  main()
  {
  	createLinkedList();
  	dsp();
  	int l;
  	printf("Enter node no after which a new node will be inserted: ");
  	scanf("%d",&l);
  	insert(l);
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
  		printf("1. Enter roll and name: ")	;
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
  		printf("\nList is empty!\n");
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
  void insert(int l)
  {
	node *p,*q=head,*loc;
	int data,i=1;
	char n[20];
	while(q!=NULL)
	{
		if(l==i)
		{
			loc=q;
			break;
		}
		i++;
		q=q->link;	
	}
	p=(node *)malloc(sizeof(node));
	if(p==NULL)
		printf("\nMemory can not be allocated.\n");
	else
	{
		printf("Enter details for the node to be inserted.\n");
		printf("Enter roll and name: ");
		scanf("%d %[^\n]s",&data,n);
		p->roll=data;
		strcpy(p->name,n);
		if(l==0)
		{
			p->link=head;
			head=p;
		}
		else
		{ 
			p->link=loc->link;
			loc->link=p;
		}
	}
  } 
  
