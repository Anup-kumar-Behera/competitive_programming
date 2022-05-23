 #include"stdio.h"
 #include"stdlib.h"
 #include"string.h"
 
 struct node{
 	int roll;
 	char name[20];
 	struct node * link;
 };
 struct node * stnode;
 void createLinkedList(int n);
 void dsp();
 void search(int );
 main()
 {
 	int n;
 	printf("\n\nLinked List: To create and display Linked List.\n");
 	printf("Enter the number of nodes :");
 	scanf("%d",&n);
 	
 	createLinkedList(n);
 	printf("\nData Entered in the List :\n");
 	dsp();
 	printf("\n----------------------------------------------------------------------\n");
 	int key;
 	printf("Enter Roll no. to Search :");
 	scanf("%d",&key);
 	search(key); 	
 }
 void createLinkedList(int n)
 {
 	struct node *p,*temp;
 	int num,i;
 	char na[20];
 	stnode=(struct node*)malloc(sizeof(struct node));
 	if(stnode==NULL)
 		printf("\nMemory can not be allocated.\n");
 	else
 	{
 		printf("1. Enter roll and name:");
 		scanf("%d %[^\n]s",&num,na);
 		stnode->roll=num;
 		strcpy(stnode->name,na);
 		stnode->link=NULL;
 		temp=stnode;
	}
	for(i=2;i<=n;i++)
	{
		p=(struct node *)malloc(sizeof(struct node));
		if(p==NULL)
			printf("\nMemory can not be allocated.n");
		else
		{
			printf("%d. Enter roll and name:",i);
			scanf("%d %[^\n]s",&num,na);
		//	scanf("%[^\n]s",na);
			p->roll=num;
			strcpy(p->name,na);
			p->link=NULL;
			temp->link=p;
			temp=temp->link;
		}
	}
 }
 void dsp()
 {

 	struct node *temp;
 	if(stnode==NULL)
 		printf("\nList is empty.\n");
 	else
 	{
 		temp=stnode;
 		while(temp!=NULL)
		{
		 	printf("Roll : %d\t Name : %s\n",temp->roll,temp->name);
 			temp=temp->link;
 		}
	}
 }
 void search(int key)
 {
 	struct node *loc=NULL; 
 	struct node *p=stnode;
 	while(p!=NULL)
 	{
 		if(key==p->roll)
 		{
			loc=p;
			break;
		}	
 		else
		 	p=p->link;
	}
	if(p==NULL)
	{
		loc=NULL;
		printf("\nITEM NOT found!\n");
	}	
	else
	{
		printf("\nRoll: %d\t Name: %s\n",loc->roll,loc->name);
	}
 }
