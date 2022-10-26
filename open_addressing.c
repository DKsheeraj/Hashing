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
        while (pointer[index + 1] != NULL)
        {
            index++;
            index %= M;
        }
        pointer[index + 1] = newNode;
    }
    N++;
}

void search(int value)
{
    int index = value % M;
    MAP temp = pointer[index];
   
    if(temp == NULL){
        printf("Value not found\n");
        return;
    }

    while(index < M){
        if(pointer[index]->data == value){
            printf("Value found\n");
            return;
        }
        index++;
    }
    printf("Value not found\n");

    
}

void delete (int value)
{
    int index = value % M;
    MAP temp = pointer[index];
   
    if(temp == NULL){
        printf("Value not found\n");
        return;
    }

    while(index < M){
        if(pointer[index]->data == value){
            pointer[index] = NULL;
            return;
        }
        index++;
    }
    printf("Value not found\n");

}

void print()
{
    int i;

    for (i = 0; i < M; i++)
    {
        MAP temp = pointer[i];
        printf("pointer[%d]-->", i);
        if (temp != NULL)
        {
            printf("%d\n", temp->data);
            continue;
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
    insert(10);

    delete(4);
    delete(6);

    // delete(3);
    print();

    return 0;
}