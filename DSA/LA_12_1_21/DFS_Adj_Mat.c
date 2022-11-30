/*
    Name: Om Vivek Gharge
    PRN: 2020BTEIT00041
    DFS Traversal Using Adjacency Matrix
    Batch: S3
    ESE
    Date: 12/01/21
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL;

// Inserting in Stack
void insert(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = t;
    }
}

// Deleting from Stack
int delete()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
        printf("Stack is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void DFS(int G[][6], int start, int n)
{
    static int visited[6] = {0};
    int j;
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
    // Initializing array to zero , No. of vertices = 4
    int G[6][6] = {{0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0},
                   {0, 1, 0, 0, 1, 0},
                   {0, 0, 1, 1, 0, 1},
                   {0, 0, 1, 1, 1, 0}};

            /*
            
                    1
                   / \
                  2---3
                   \ /
                    4
                    |
                    5
                        
            */
    
    
    printf("\nDFS Transversal with node 1: \n");
    DFS(G, 1, 6);

    return 0;
}