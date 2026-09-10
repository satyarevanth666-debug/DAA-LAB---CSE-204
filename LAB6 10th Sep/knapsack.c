#include <stdio.h>
struct Item
{
    int profit;
    int weight;
    float ratio;
};

int main()
{
    int n, capacity;
    float totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
            printf("Taken: 100%% of item %d\n", i + 1);
        }
        else
        {
            float fraction = (float)capacity / item[i].weight;
            totalProfit = totalProfit + item[i].profit * fraction;
            printf("Taken: %.2f%% of item %d\n", fraction * 100, i + 1);
            capacity = 0;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}