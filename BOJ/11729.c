#include <stdio.h>
#include <math.h>

void hanoi(int x, int y, int k) {//k level tower moved x -> y
	if(k==1) {
		printf("%d %d\n",x,y);
		return;
	}
	hanoi(x,6-x-y,k-1);
	printf("%d %d\n",x,y);
	hanoi(6-x-y,y,k-1);
}

int main(void){
	int N;
	scanf("%d",&N);
	printf("%d\n",(int)(pow(2,N)-1));
	hanoi(1,3,N);

	return 0;
}
