#include <stdio.h>
#include <stdlib.h>

//When use this ==> quickSort(arr,first index, last index) !!!(last index = length(arr)-1)!!!
void quickSort(int *arr, int l, int r) {
	//l : leftmost index. r : rightmost index.
	//Set pivot. Left things are smaller than pivot. Right things are bigger than pivot.
	//leftmost index`s number set pivot.
	//arr size = r - l + 1

	if(l >= r)
		return;

	int i, pivot = arr[l];
	int larr[r-l+1];
	int rarr[r-l+1];
	int l_index=0,r_index=0;

	for(i=l+1 ; i <= r ; i++) {
		if(arr[i] >= pivot)
			rarr[r_index++] = arr[i];
		else
			larr[l_index++] = arr[i];
	}
	//r_index indicate end of the rarr`s index + 1. left_index is the same.

	//larr,pivot,rarr
	for(i=0 ; i < l_index ; i++) {
		arr[i+l] = larr[i+l-l];
	}
	arr[l+l_index] = pivot;
	for(i=0 ; i < r_index ; i++) {
		arr[l+l_index+1+i] = rarr[i];
	}
	quickSort(arr,l,l+l_index-1);
	quickSort(arr,l+l_index+1,r);

}

int main(void) {
	int arr[10];

	for(int i=0;i<10;i++)
		arr[i] = rand();

	quickSort(arr,0,9);
	for(int i=0;i<10;i++)
		printf("%d ",arr[i]);

	return 0;
}
