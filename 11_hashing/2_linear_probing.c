#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % 10;
}

int probe(int H[], int key)
{
    int index = hash(key); // hash index
    int i = 0;

    while (H[(index + i) % SIZE] != 0)
    {
        i++;
    }

    return (index + i) % SIZE;
}

void Insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
    {
        index = probe(H, key);
    }

    H[index] = key;
}

int main()
{
    int HT[10] = {0};

    Insert(HT, 12);

    return 0;
}