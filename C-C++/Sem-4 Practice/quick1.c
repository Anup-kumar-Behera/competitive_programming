#include<iostream>
#incldue<cstdio>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node;

void push(node **head_ref,int new_data)
{
	node *new_node = new node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printlist(node *Node)
{
	while(Node != 0)
	{
		printf("%d ",Node->data);
		Node = Node->next;
	}
	printf("\n");
}
node *getTail(node *cur)
{
	while(cur != 0 && cur->next != 0)
		cur = cur->next;
	return cur;
}

node *partition(node *head,node *end,node **newHead,node **newEnd)
{
	node *pivot = end;
	node *prev = 0, *cur = head,*tail = pivot;
	
	while(cur != pivot)
	{
		if(cur->data < pivot->data)
		{
			(if(*newHead) == NULL)
				(*newHead) = cur;
				
			prev = cur;
			cur = cur->next;
		}
		else
		{
			if(prev)
				prev->next = cur->next;
			node *temp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}
	if((*newHead) == NULL)
		(*newHead) = pivot;
	(*newEnd) = tail;
	
	return pivot;
}

node *quickSortRecur(node *head,node *end)
{
	if(!head || head == end)
		return head;
	node *newHead = NULL, *newEnd = NULL;
	
	node *pivot = partition(head,end,&newHead,&newEnd);
	
	if(newHead != pivot)
	{
		node *temp = newHead;
		while(temp->next != pivot)
			temp = temp->next;
		temp->next = pivot; 
	}
	
	pivot->next = quickSortRecur(pivot->next,newEnd);
	
	return newHead;
}
void quickSort(node **headRef)
{
	(*headRef) = quickSortRecur(*headRef,getTail(*headRef));
	return ;
}
