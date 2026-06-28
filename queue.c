#include<stdio.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

void enqueue()
{
    int x;

    if(rear == N - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &x);

        if(front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
    }
    else if(front == rear)
    {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void peek()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void isFull()
{
    if(rear == N - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Queue is Not Full\n");
    }
}

void isEmpty()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is Not Empty\n");
    }
}

int main()
{
    int choice, c = 1;

    while(c == 1)
    {
        printf("\n----- Queue Operations -----");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. isFull()");
        printf("\n6. isEmpty()");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isFull();
                break;

            case 6:
                isEmpty();
                break;

            default:
                printf("Invalid Choice\n");
        }

        printf("\nDo you want to continue (1/0): ");
        scanf("%d", &c);
    }

    return 0;
}
