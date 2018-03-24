#include <stdio.h>

int main(void) {
	int N,input,i,a[10001];

	for(i=1;i<=10000;i++)
		a[i]=0;
	scanf("%d",&N);
	for(i=0;i<N;i++) {
		scanf("%d",&input);
		a[input]++;
	}
	for(i=1;i<=10000;i++) {
		if(a[i]) {
			while(a[i]) {
				printf("%d\n",i);
				a[i]--;
			}
		}
	}

	return 0;
}
