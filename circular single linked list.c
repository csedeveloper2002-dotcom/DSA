#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void create()
{
    int choice = 1;

    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if(head == NULL)
        {
            head = temp = newnode;
            newnode->next = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }
}

void display()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

void insert_at_begin()
{
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &x);

    newnode->data = x;

    if(head == NULL)
    {
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_at_end()
{
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &x);

    newnode->data = x;

    if(head == NULL)
    {
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
        temp->next = head;
    }
}

int main()
{
    int ch, c = 1;

    create();

    while(c)
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert_at_begin();
                break;

            case 2:
                insert_at_end();
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid Choice\n");
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &c);
    }

    return 0;
}
