
#include<stdio.h>
int main() {
	int n,a,r,sum=0;
	printf("Enter number of terms : ");
	scanf("%d",&n);
	printf("Enter first term : ");
	scanf("%d",&a);
	printf("Enter common ratio : ");
	scanf("%d",&r);
	for(int i = 1; i<=n; i++) {
		sum = sum + a;
		a = a * r;
	}
	printf("Total Sum = %d",sum);
	return 0;
}

	















