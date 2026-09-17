#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int find(int parent[], int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

void unionSet(int parent[], int a, int b)
{
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    parent[rootA] = rootB;
}

int main()
{
    int n, e;
    struct Edge edges[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination weight):\n");

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Sort edges according to weight
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[100];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0;
    int total = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV)
        {
            printf("%d - %d : %d\n", u, v, edges[i].w);

            total += edges[i].w;
            unionSet(parent, rootU, rootV);

            count++;
        }
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}