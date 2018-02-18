#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} node;


void insert(node *list, int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    if(list->next == NULL)
    {
        list->next=temp;
    }
    else
    {
        while(list->next != NULL)
        {
            list=list->next;
        }
        list->next=temp;
    }
}


void insert_front(node *list, int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    if(list->next == NULL)
    {
        list->next=temp;
    }
    else
    {
        temp->next=list->next;
        list->next=temp;
    }
}


void insert_after(node *list, int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    if(list->next == NULL)
    {
        printf("No node found at the front\n");
    }
    else
    {
        temp->next=list->next->next;
        list->next->next=temp;
    }
}


void update(node *list, int data, int new_data)
{
    node *temp;

    if(list->next == NULL)
    {
        printf("No node found\n");
    }
    else
    {
        while(list->next->data != data)
        {
            list=list->next;
        }
        list->next->data=new_data;
    }
}


void del(node *list, int data)
{
    node *temp;

    if(list->next == NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        while(list->next->data != data)
        {
            list=list->next;
        }
        temp=list->next;
        list->next=list->next->next;
        free(temp);
    }
}


void display(node *list)
{
    printf("\nThe Linked List Display\n");

    if(list->next == NULL)
    {
        printf("No nodes found!\n");
        return;
    }

    while(list->next != NULL)
    {
        printf("%d", list->next->data);

        if(list->next->next != NULL)
        {
            printf(" => ");
        }

        list=list->next;
    }
    printf("\n");
}


void recDisplay(node *list, node *start)
{
    if((list == start) && (start->next == NULL))
    {
        printf("No nodes found!\n");
        return;
    }

    if(list->next == NULL)
    {
        return;
    }

    recDisplay(list->next, start);
    printf("%d", list->next->data);

    if(list->next == start->next)
    {
        printf("\n");
    }
    else
    {
        printf(" => ");
    }
}


node* iterate(node *list)
{
    node *prev, *current, *next, *temp, *n_temp;

    n_temp=(node*)malloc(sizeof(node));

    temp=list;
    prev=NULL;

    if(list->next == NULL)
    {
        return;
    }
    list=list->next;
    free(temp);

    while(list->next != NULL)
    {
        current=list;
        next=list->next;
        list->next=prev;
        prev=current;
        list=next;
    }
    list->next=prev;
    n_temp->next=list;
    list=n_temp;

    return list;
}


int count(node *list)
{
    int c=0;

    if(list->next == NULL)
    {
        return 0;
    }
    else
    {
        while(list->next != NULL)
        {
            c++;
            list=list->next;
        }
        return c;
    }
}


int main()
{
    int n, i, d, n_d;

    node *list=(node*)malloc(sizeof(node));
    list->next=NULL;

    printf("Insert the number of nodes: ");
    scanf("%d", &n);

    printf("Insert nodes: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &d);
        insert(list, d);
    }
    display(list);

    printf("\nInsert node at the front: ");
    scanf("%d", &d);
    insert_front(list, d);
    display(list);

    printf("\nInsert node after a node: ");
    scanf("%d", &d);
    insert_after(list, d);
    display(list);

    printf("\nUpdate node data: ");
    scanf("%d", &d);
    printf("New data: ");
    scanf("%d", &n_d);
    update(list, d, n_d);
    display(list);

    printf("\nDelete node: ");
    scanf("%d", &d);
    del(list, d);
    display(list);

    printf("\nReversed Linked List (Iteration Method)");
    list=iterate(list);
    display(list);

    printf("\nLinked List Recursive Display\n");
    recDisplay(list, list);

    printf("\nTotal Nodes: %d\n", count(list));

    return 0;
}
