#include <stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int maxCrossingSum(int a[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = -999999;
    int rightSum = -999999;
    for (int i = mid; i >= low; i--) {
        sum = sum + a[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + a[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubarraySum(int a[], int low, int high)
{
    if (low == high)
        return a[low];
    int mid = (low + high) / 2;
    int left = maxSubarraySum(a, low, mid);
    int right = maxSubarraySum(a, mid + 1, high);
    int cross = maxCrossingSum(a, low, mid, high);
    return max(left, max(right, cross));
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int result = maxSubarraySum(a, 0, n - 1);
    printf("Maximum Sum = %d\n", result);
    return 0;
}