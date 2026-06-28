#include<stdio.h>

#define N 5

int top = -1;
int stack[N];

void display()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int i;
        for(i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

void push()
{
    int x;

    if(top == N - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

int main()
{
    int choice, c = 1;

    while(c == 1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            default:
                printf("Invalid Choice\n");
        }

        printf("\nDo you want to continue (1/0): ");
        scanf("%d", &c);
    }

    return 0;
}
