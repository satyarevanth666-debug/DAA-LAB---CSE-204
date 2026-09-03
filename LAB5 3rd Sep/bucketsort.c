#include <stdio.h>

void bucketSort(int arr[], int n)
{
    int buckets[10][100];
    int count[10] = {0};

    int i, j, k;
    int bucketIndex;

    for (i = 0; i < n; i++)
    {
        bucketIndex = arr[i] / 10;
        buckets[bucketIndex][count[bucketIndex]] = arr[i];
        count[bucketIndex]++;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i] - 1; j++)
        {
            for (k = 0; k < count[i] - j - 1; k++)
            {
                if (buckets[i][k] > buckets[i][k + 1])
                {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    k = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main()
{
    int arr[100];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}