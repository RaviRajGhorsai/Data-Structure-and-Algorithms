#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--)
        MaxHeapify(arr,n,i);
    
    for(int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        MaxHeapify(arr,i,0);
    }
}

void printarray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[] = {1,12,9,5,6,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,n);

    printf("Sorted array is \n");
    printarray(arr,n);

    return 0;
}