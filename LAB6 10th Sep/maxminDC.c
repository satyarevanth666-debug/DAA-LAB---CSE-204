#include<stdio.h>
void maxmin(int arr[], int low, int high, int *max, int *min) {
    int mid;
    int max1,min1,max2,min2;
    if(low==high) {
        *max = arr[low];
        *min = arr[low];
    } else if(low == high - 1) {
        *max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        *min = (arr[low] < arr[high]) ? arr[low] : arr[high];
    } else {
        mid = (low + high) / 2;
        maxmin(arr, low, mid, &max1, &min1);
        maxmin(arr, mid + 1, high, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}
int main() {
    int arr[100], n, i, max, min;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    maxmin(arr, 0, n - 1, &max, &min);
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);
}