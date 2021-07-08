#include "queue.h"

void BFS(int G[][7], int start, int n)
{
    int i = start, j;

    int visited[7] = {0}; // array of visited nodes

    printf("%d ", i);
    visited[i] = 1; // set starting element as visited
    enqueue(i);     // enqueue the visited element into queue

    while (!isEmpty())
    {
        i = dequeue(); // take out visited node for exploring

        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0) // if node is node visited
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main()
{
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 2, 7);

    return 0;
}