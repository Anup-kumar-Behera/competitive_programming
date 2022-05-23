#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    char name[20];
    struct node *next;
}node;
node *head = 0;
void dsp();
void reverse();
void create_list();

int main()
{
    int n;
    do
    {
        printf("\nEnter 1 to insert data.\n");
        printf("Enter 2 to dsp data.\n");
        printf("Enter 3 to dsp reversed list.\n");
        printf("Enter choice: ");
        scanf("%d",&n);
        if(n == 1)
        {   
            create_list();
        }
        else if(n == 2)
        {
            printf("Displaying list data.\n");
            dsp();
        }
        else if(n == 3)
        {
            printf("List reversed.\n");
            reverse();
        }
    }while(n!=0);
    return 0;
}
void create_list()
{
    int data,i = 2;
    char name[20],x[5];

    head = (node *)malloc(sizeof(node));
    node *p = head;
    if(head == 0)
        printf("Overflow.\n");
    else
    {
        printf("1. Enter roll and name: ");
        scanf("%d %s",&data,name);
        p->data = data;
        strcpy(p->name,name);

        while(1)
        {
            printf("Do you want to continue(Y/N): ");
            scanf("%s",x);
            if(strcmp(x,"N") == 0)
                break;
            node *q = (node *)malloc(sizeof(node));
            if(q == 0)
                printf("Overflow.\n");
            else
            {
                printf("%d. Enter roll and name: ",i);
                scanf("%d %s",&data,name);
                q->data = data;
                strcpy(q->name,name);
                q->next = 0;
                p->next = q;
                p = p->next;
                i++;
            }   
        }
        p->next = 0;
    }
}

void dsp()
{
    if(head == 0)
        printf("Underflow.\n");
    else
    {
        node *p = head;
        while(p != 0 )
        {
            printf("Roll: %d\tName: %s\n",p->data,p->name);
            p = p->next;
            
        }
    }
    
}
void reverse()
{
    node *current,*n=0,*prev=0;
    current = head;
    while(current != 0)
    {
        n = current->next;
        current->next = 0;
        prev = current;
        current = n;
    }
    head = prev;
}