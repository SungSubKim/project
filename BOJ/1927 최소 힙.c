#include <stdio.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//Minimum heap
int main(void) {
	int heapArr[100005];
	int heapLength=0;
	int N,x,temp,i,min;

	scanf("%d",&N);
	while(N--){
		scanf("%d",&x);
		if(x==0){
			//pop data :
			//pop first node.
			//put last node to first node.
			//do compare three node (node i, left child node(2*i), right child node(2*i+1))
			//while node i has appropriate position.
			if(heapLength == 0)
				printf("0\n");
			else {
				printf("%d\n",heapArr[1]);
				heapArr[1] = heapArr[heapLength--];
				i=1;
				while(i<=heapLength) {
					min = heapArr[i];
					//min = minimum among three nodes

					if(i*2<=heapLength && min > heapArr[i*2])
						min = heapArr[i*2];
					if(i*2+1<=heapLength && min > heapArr[i*2+1])
						min = heapArr[i*2+1];
					if(min == heapArr[i])
						break;
					else{
						if(min == heapArr[i*2]) {
							swap(&heapArr[i],&heapArr[i*2]);
							i=i*2;
						} else {
							swap(&heapArr[i],&heapArr[i*2+1]);
							i=i*2+1;
						}
					}
				}
			}

		} else {
			//insert data :
			//insert new data to final node.
			//Next compare with parent`s node while first node or appropriate position.
			heapArr[++heapLength] = x;
			temp = heapLength;	//store at temp because of changing
			while(temp/2) {
				if(heapArr[temp/2] <= heapArr[temp])
					break;
				else {
					swap(&heapArr[temp/2],&heapArr[temp]);
				}
				temp/=2;
			}
		}
	}
	return 0;
}
