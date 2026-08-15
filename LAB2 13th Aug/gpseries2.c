#include<stdio.h> 
#include<math.h>
int main() {
	int a,r,n;
	int sum = 0;
	printf("Enter n : ");
	scanf("%d",&n);
	printf("Enter a : ");
	scanf("%d",&a);
	printf("Enter r : ");
	scanf("%d",&r);
	sum = (a * (pow(r,n) - 1)) / (r - 1);
	printf("Sum of the series is : %d",sum);
	return 0;
}