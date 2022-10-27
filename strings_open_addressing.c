#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map // Declaration of node
{
    int data;
    char string[100];
    struct map *next;
} map;

typedef map *MAP;
int N = 0, M = 7;
MAP pointer[10]; // creates an array of pointers each of type: map structure

void initialize()
{
    int i;
    for (i = 0; i < M; i++)
        pointer[i] = NULL;
}

void insert(char string[])
{
    // create a newnode with value
    MAP newNode = malloc(sizeof(map));
    int value = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        newNode->string[i] = string[i];
        value += string[i];
    }
    newNode->string[strlen(string)] = '\0';

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

void search(char string[])
{
    int value = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        value += string[i];
    }
    int index = value % M;
    MAP temp = pointer[index];

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    while (index < M)
    {
        if (pointer[index] != NULL)
        {

            if (strcmp(pointer[index]->string, string) == 0)
            {
                printf("Value found\n");
                return;
            }
        }

        index++;
    }
    printf("Value not found\n");
}

void delete (char string[])
{
    int value = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        value += string[i];
    }
    int index = value % M;
    MAP temp = pointer[index];

    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    while (index < M)
    {
        if (pointer[index] != NULL)
        {

            if (strcmp(pointer[index]->string, string) == 0)
            {
                pointer[index] = NULL;
                return;
            }
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
            printf("%s\n", temp->string);
            continue;
        }

        printf("NULL\n");
    }
}

int main()
{
    // init array of list to NULL
    initialize();

    insert("ad");
    insert("bc");
    insert("datta");
    insert("ksheeraj");
    insert("of");
    

    print();

    return 0;
}