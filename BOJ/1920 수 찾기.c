#include <stdio.h>
#define INT_MAX 2147483647
#define START_INDEX 1

void mergeSort(int *arr, int p, int r);//merge sort 오름차순
void merge(int *arr, int p, int q, int r);//merge func
int binarySearch(int *arr, int size, int data);

int main(void) {
	int n,m,i,value,a[100005];

	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//ascending sort O(nlgn)
	mergeSort(a,1,n);

	scanf("%d",&m);
	//binary search O(lgn)
	while(m--) {
		scanf("%d",&value);
		if(binarySearch(a,n,value)==-1)
			puts("0");
		else
			puts("1");
	}
}

void mergeSort(int *arr, int p, int r) {
	if(p<r) {
		int q = (p+r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int *arr, int p, int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;
	int i,j,k;
	int left[n1+1],right[n2+1];

	//left,right배열에 현재 배열정보 저장
	for(i=0;i<n1;i++)
		left[i] = arr[p+i];
	for(i=0;i<n2;i++)
		right[i] = arr[q+1+i];
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	//arr에 다시 병합해서 정렬
	j=0;k=0;
	for(i=p;i<=r;i++) {
		if(left[j]<=right[k]) {
			arr[i] = left[j];
			j++;
		} else {
			arr[i] = right[k];
			k++;
		}
	}
}

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
