#include<stdio.h>

#define N 5

int deque[N];
int front = -1, rear = -1;

void insertFront()
{
    int x;

    if((front == 0 && rear == N-1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &x);

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = N - 1;
    }
    else
    {
        front--;
    }

    deque[front] = x;
}

void insertRear()
{
    int x;

    if((front == 0 && rear == N-1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &x);

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == N - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
}

void deleteFront()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == N - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if(front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = N - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");

    i = front;

    while(i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }

    printf("%d\n", deque[rear]);
}

int main()
{
    int choice, c = 1;

    while(c)
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
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
