#include <stdio.h>

int fiveToSix(int n) {
	int i,check;
	for(i=1;;i*=10) {
		check = n/i;
		if(check==0)
			break;
		check %= 10;
		if(check==5){
			n-=5*i;
			n+=6*i;
		}
	}
	return n;
}
int sixToFive(int n) {
	int i,check;
	for(i=1;;i*=10) {
		check = n/i;
		if(check==0)
			break;
		check %= 10;
		if(check==6){
			n-=6*i;
			n+=5*i;
		}
	}
	return n;
}

int main(){
	int n,m;

	scanf("%d %d",&n,&m);

	printf("%d %d",sixToFive(n)+sixToFive(m),fiveToSix(n)+fiveToSix(m));
	return 0;
}
