
#include <stdio.h>
#include <stdlib.h>
#include "chains.h"

// get hash value
int hash(int key)
{
    return key % 10;
}

void Insert(struct Node *HT[], int key)
{
    int index = hash(key);
    SortedInsert(&HT[index], key);
}

int main()
{
    struct Node *HT[10]; // hash table
    struct Node *temp;
    for (int i = 0; i < 10; i++) // initialize hash table with null
    {
        HT[i] = NULL;
    }

    Insert(HT, 12);
    Insert(HT, 13);

    temp = Search(HT[hash(13)], 13);

    printf("\n%d ", temp->data);
    return 0;
}