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
 
 main()
 {
 	int n;
 	printf("\n\nLinked List: To create and display Linked List.\n");
 	printf("Enter the number of nodes :");
 	scanf("%d",&n);
 	
 	createLinkedList(n);
 	printf("\nData Entered in the List :\n");
 	dsp();
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
 		printf("Enter roll and name for node 1:");
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
			printf("Enter roll and name for node %d:",i);
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
