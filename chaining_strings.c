#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct map // Declaration of node
{
    int data;
    char string[100];
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

void insert(char string[])
{
    int value = 0;
    MAP newNode = malloc(sizeof(map));
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

void search(char string[])
{
    int value = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        value += string[i];
    }
    int index = value % M;
    MAP temp = pointer[index];
    while (temp)
    {
        if (strcmp(temp->string, string) == 0)
        {
            printf("Value found\n");
            return;
        }
        temp = temp->next;
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
    MAP temp = pointer[index], to_be_freed;
    if (temp != NULL)
    {
        if (strcmp(temp->string, string) == 0)
        {
            pointer[index] = temp->next;
            free(temp);
            printf("%s removed\n", string);
            return;
        }
        else
        {
            while (temp->next)
            {
                if (strcmp(temp->next->string, string) == 0)
                {
                    to_be_freed = temp->next;
                    temp->next = temp->next->next;
                    free(to_be_freed);
                    printf("%s removed\n", string);
                    return;
                }
                temp = temp->next;
            }
        }
    }

    printf("%s not found\n", string);
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
            printf("%s[%d] -->", temp->string, temp->data);
            temp = temp->next;
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
    
    delete("of");
    print();
    return 0;
}
