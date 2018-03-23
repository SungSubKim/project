#include <stdio.h>
#define INT_MAX 2147483647

void swap(int *a, int *b);//a,b swap�Լ�
void selectionSort(int *arr, int n);//selection sort ��������
void bubbleSort(int *arr, int n);//bubble sort ��������
void insertionSort(int *arr, int n);//insertion sort ��������
void insertionSort2(int *arr, int n);//�������� insertion sort ��������
void mergeSort(int *arr, int p, int r);//merge sort ��������
void merge(int *arr, int p, int q, int r);//merge func

int main(void) {
	int n,i,arr[1000001];
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	//���� ����
//	selectionSort(arr,n);
//	bubbleSort(arr,n);
//	insertionSort2(arr,n);
	mergeSort(arr,0,n-1);

	for(i=0;i<n;i++) {
		printf("%d\n",arr[i]);
	}

	return 0;
}

void swap(int *a, int *b) {
	int n;
	n=*a;
	*a=*b;
	*b=n;
}


void selectionSort(int *arr, int n) {
	int i,j;
	for(i=0;i<n-1;i++) {
		for(j=i+1;j<n;j++) {
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
		}
	}
}


void bubbleSort(int *arr, int n) {
	int i,j;
	for(i=0;i<n-1;i++) {
		for(j=i+1;j<n;j++) {
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
		}
	}
}

void insertionSort(int *arr, int n) {
	int i,j,k;
	for(i=1;i<n;i++) {
		k=arr[i];
		for(j=0;j<i;j++) {
			if(k<arr[j]) {
				swap(&arr[j],&arr[i]);
			}
		}
	}
}

void insertionSort2(int *arr, int n) {
	int i,j,k;

	for(j=1;j<n;j++){
		k=arr[j];
		i=j-1;
		while(i>=0 && arr[i]>k) {
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=k;
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

	//left,right�迭�� ���� �迭���� ����
	for(i=0;i<n1;i++)
		left[i] = arr[p+i];
	for(i=0;i<n2;i++)
		right[i] = arr[q+1+i];
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	//arr�� �ٽ� �����ؼ� ����
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
