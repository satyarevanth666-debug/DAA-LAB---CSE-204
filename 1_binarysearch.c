#include<stdio.h>
int main()
{
    int n,key;
    printf("Enter number of elements in the array : ");
    scanf("%d",&n);
    printf("Enter target element to be searched : ");
    scanf("%d",&key);
    int arr[n];
    printf("Enter array elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element %d found at %d position in the array.",key,mid+1);
            return 0;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("Element %d not found in the array.",key);
    return 0;
}













