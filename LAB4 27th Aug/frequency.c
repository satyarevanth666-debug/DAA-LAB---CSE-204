#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hash table
    int hash[1000] = {0};

    // Count frequency
    for (i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // Display frequency of distinct elements
    printf("\nFrequency of elements:\n");
    for (i = 0; i < n; i++) {
        // Print only first occurrence
        int j, found = 0;

        for (j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%d -> %d\n", arr[i], hash[arr[i]]);
        }
    }

    return 0;
}