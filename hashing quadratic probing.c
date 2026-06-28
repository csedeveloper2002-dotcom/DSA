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
    int key, index, i;

    printf("Enter element: ");
    scanf("%d", &key);

    index = key % SIZE;

    for(i = 0; i < SIZE; i++)
    {
        int newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            printf("Inserted at index %d\n", newIndex);
            return;
        }
    }

    printf("Hash Table is Full\n");
}

void search()
{
    int key, index, i;

    printf("Enter element to search: ");
    scanf("%d", &key);

    index = key % SIZE;

    for(i = 0; i < SIZE; i++)
    {
        int newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == key)
        {
            printf("Element found at index %d\n", newIndex);
            return;
        }

        if(hashTable[newIndex] == -1)
            break;
    }

    printf("Element not found\n");
}

void display()
{
    int i;

    printf("\nHash Table\n");

    for(i = 0; i < SIZE; i++)
    {
        if(hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
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
