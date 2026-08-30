#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];

int hash(int key)
{
    return (key % SIZE + SIZE) % SIZE;
}

int search(int key)
{
    int index = hash(key);
    if (hashTable[index] == key)
        return 1;
    return 0;
}

int main()
{
    int n, T, key;
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter target T: ");
    scanf("%d", &T);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &key);
        int complement = T - key;
        if (search(complement))
        {
            printf("Yes, two elements exist whose sum is %d\n", T);
            return 0;
        }

        int index = hash(key);
        hashTable[index] = key;
    }

    printf("No, such two elements do not exist\n");

    return 0;
}





