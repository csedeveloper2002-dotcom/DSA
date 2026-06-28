#include<stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;
    for(i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert()
{
    int key, index;

    printf("Enter element: ");
    scanf("%d", &key);

    index = key % SIZE;

    while(hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

void search()
{
    int key, index, start;

    printf("Enter element to search: ");
    scanf("%d", &key);

    index = key % SIZE;
    start = index;

    while(hashTable[index] != -1)
    {
        if(hashTable[index] == key)
        {
            printf("Element found at index %d\n", index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("Element not found\n");
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("%d : ", i);

        if(hashTable[i] == -1)
            printf("Empty");
        else
            printf("%d", hashTable[i]);

        printf("\n");
    }
}

int main()
{
    int choice, c = 1;

    initialize();

    while(c == 1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
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
