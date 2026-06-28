#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *head, *temp;

void display()
{
    temp = head;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_begin()
{
    int y;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &y);

    newnode->data = y;
    newnode->next = head;
    head = newnode;

    if(temp == NULL)
        temp = head;
}

void insert_at_end()
{
    int y;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &y);

    newnode->data = y;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

int main()
{
    head = NULL;
    temp = NULL;

    int choice = 1;

    while(choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? Press 1 else 0: ");
        scanf("%d", &choice);
    }

    int a = 1;

    while(a == 1)
    {
        int s;

        printf("\nEnter\n1 - Insert at Beginning\n2 - Insert at End\n3 - Display\nChoice: ");
        scanf("%d", &s);

        switch(s)
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

        printf("Continue (1/0): ");
        scanf("%d", &a);
    }

    return 0;
}
