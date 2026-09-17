#include <stdio.h>

#define INF 9999

int main()
{
    int n;
    int cost[100][100];
    int visited[100] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    int edges = 0;
    int total = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1)
        {
            printf("MST does not exist.\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        total += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}