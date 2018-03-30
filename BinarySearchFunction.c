#include <stdio.h>
#define START_INDEX 0

//practice binary search (assume that array is ascending sorted)
int binarySearch(int *arr, int size, int data) {//return searched value`s index
	int high=size-1+START_INDEX;
	int low=START_INDEX;
	int mid;
	//break when low=high or low over high. and this means that there is no data
	while(low <= high) {
		mid = (high+low)>>1;
		if(arr[mid] == data)
			return mid;
		else if(arr[mid] > data) {
			high = mid-1;
		} else if(arr[mid] < data) {
			low = mid+1;
		}
	}
	return -1;
}

int main(void) {
	int a[7]={1,2,3,4,5,6,7};

	printf("%d",binarySearch(a,7,7));
	printf("end");
	return 0;
}
