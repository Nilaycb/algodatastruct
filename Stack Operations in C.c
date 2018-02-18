#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} node;


typedef struct Pop_Node
{
    int data;
    int returned;
} pop_node;


int push(node *stack, int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=stack->next;

    stack->next=temp;
    return stack->next->data;
}


pop_node* pop(node *stack)
{
    pop_node *res=(pop_node*)malloc(sizeof(pop_node));
    res->returned=0;

    node *temp;

    if(stack->next == NULL)
    {
        return res;
    }

    temp=stack->next;
    res->data=stack->next->data;
    res->returned=1;
    stack->next=stack->next->next;
    free(temp);

    return res;
}


void display(node *stack)
{
    printf("\nDisplay of the Stack\n");

    if(stack->next == NULL)
    {
        printf("The Stack is empty\n");
        return;
    }

    while(stack->next != NULL)
    {
        printf("%d", stack->next->data);

        if(stack->next->next != NULL)
        {
            printf(" <= ");
        }

        stack=stack->next;
    }
    printf("\n");
}


int main()
{
    int n, i, data, pushed;

    node *stack=(node*)malloc(sizeof(node));
    stack->next=NULL;

    printf("Enter the initial size of the Stack: ");
    scanf("%d", &n);

    printf("\nPush %d data to the Stack: \n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &data);
        pushed=push(stack, data);

        printf("%d pushed to the Stack\n", pushed);
    }

    display(stack);

    printf("\nPopping data from the Stack: ");
    pop_node *popped;
    popped=pop(stack);

    if(popped->returned == 1)
    {
        printf("\n%d popped from the Stack\n", popped->data);
    }
    else
    {
        printf("\nNothing to pop, the Stack is empty\n");
    }

    display(stack);

    printf("\nPush data to the Stack: ");
    scanf("%d", &data);
    pushed=push(stack, data);
    printf("%d pushed to the Stack\n", pushed);

    display(stack);

    return 0;
}
