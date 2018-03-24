#include <stdio.h>

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void printarr(int *a) {
	int i;
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main(void) {
	int i,j,a[5];
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			if(a[j] > a[j+1]) {
				swap(&a[j],&a[j+1]);
				printarr(a);
			}
		}
	}
	return 0;
}
