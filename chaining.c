#include <stdio.h>
#include <stdlib.h>

typedef struct map // Declaration of node
{
    int data;
    struct map *next;
} map;

typedef map *MAP;
int N = 0, M = 7;
MAP pointer[10], pointer1[10]; // creates an array of pointers each of type: map structure

void initialize()
{
    int i;
    for (i = 0; i < M; i++)
        pointer[i] = NULL;
}

void insert(int value)
{
    // create a newnode with value
    MAP newNode = malloc(sizeof(map));
    newNode->data = value;
    newNode->next = NULL;

    // calculate hash index
    int index = value % M;

    // check if pointer[index] is empty
    if (pointer[index] == NULL)
    {
        pointer[index] = newNode;
    }
    // collision
    else
    {
        // add the node at the end of pointer[index].
        MAP temp = pointer[index];
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    N++;
}

void search(int value)
{
    int index = value % M;
    MAP temp = pointer[index];
    while (temp)
    {
        if (temp->data == value)
        {
            printf("Value found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Value not found\n");
}

void delete (int value)
{
    int index = value % M;
    MAP temp = pointer[index], to_be_freed;
    if (temp != NULL)
    {
        if (temp->data == value)
        {
            pointer[index] = temp->next;
            free(temp);
            printf("%d removed\n", value);
            return;
        }
        else
        {
            while (temp->next)
            {
                if (temp->next->data == value)
                {
                    to_be_freed = temp->next;
                    temp->next = temp->next->next;
                    free(to_be_freed);
                    printf("%d removed\n", value);
                    return;
                }
                temp = temp->next;
            }
        }
    }

    printf("%d not found\n", value);
}



void print()
{
    int i;

    for (i = 0; i < M; i++)
    {
        MAP temp = pointer[i];
        printf("pointer[%d]-->", i);
        while (temp)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    // init array of list to NULL
    initialize();

    

    insert(7);
    insert(0);
    insert(3);
    insert(1);
    insert(4);
    insert(5);

    
    // search(10);
    // search(6);

    // delete(3);
    print();

    return 0;
}