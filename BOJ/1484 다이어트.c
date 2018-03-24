#include <stdio.h>
#include <math.h>

int main(void) {
	int G,i,chk=0;
	scanf("%d",&G);
	if(G==1){
		printf("-1");
		return 0;
	}
	for(i=(int)sqrt(G);i>0;i--) {
		if(G%i==0 && (i+G/i)%2==0 && G-(i+G/i)/2*(i+G/i)/2!=0){
			printf("%d\n",(i+G/i)/2);
			chk=1;
		}
	}
	if(!chk)
		printf("-1");
	return 0;
}
