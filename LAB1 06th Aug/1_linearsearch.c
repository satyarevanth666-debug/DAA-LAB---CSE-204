#include<stdio.h>
int main() 
{
	int n,key;
	printf("Enter number of elements in the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter target element to be searched : ");
	scanf("%d",&key);
	printf("Enter array elements : ");
	for(int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
		if(arr[i] == key) {
			printf("Element %d found at %d position in the array.",key,i+1);
			return 0;
               	}
	}
	printf("Element not found at any position in the given array.");
	return 0;
}