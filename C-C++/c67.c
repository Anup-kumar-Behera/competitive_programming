#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	struct node* left;
	char opr;
	struct node* right;
}node;

struct yyy{
	char opd;
	int status;
	node *link;
};
void preorder(node *);
void inorder(node *);
void postorder(node *);

main()
{
	char x[]="683/7*+1-2+";
	struct yyy stack[strlen(x)];
	int i,j=-1;
	node *p,*r,*l,*root;
	
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			j++;
			stack[j].opd=x[i];
			stack[j].status=0;
			stack[j].link=0;
		}
		else
		{
			p=(node *)malloc(sizeof(node));
			p->opr=x[i];
			if(stack[j].status==0)
			{
				r=(node *)malloc(sizeof(node));
				r->opr=stack[j].opd;
				p->right=r;
				r->left=0;
				r->right=0;
			}
			else
			{
				p->right=stack[j].link;
			}
			j--;
			if(stack[j].status==0)
			{
				l=(node *)malloc(sizeof(node));
				l->opr=stack[j].opd;
				p->left=l;
				l->left=0;
				l->right=0;
			}
			else
			{
				p->left=stack[j].link;
			}
			stack[j].link=p;
			stack[j].status=l;
		}
	}
	root=stack[j].link;
	inorder(root);
		printf("\n");
	preorder(root);
		printf("\n");
	postorder(root);
}
void inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d ",p->opr);
		inorder(p->right);
	}
}
void preorder(node *p)
{
	if(p)
	{
		printf("%d ",p->opr);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(node *p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->opr);
	}
}
