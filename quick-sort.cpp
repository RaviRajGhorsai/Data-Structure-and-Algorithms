#include<stdio.h>
#define n 7

int arr[] = {5,3,8,1,4,6,27};

int partition(int start, int end){
    int pivot = start+1, temp;
    while(start<end){
        while(arr[start]<=arr[pivot]){
            start++;
        }
        while(arr[end]>arr[pivot]){
            end--;
        }
        if(start<end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }       
    }
    temp = arr[pivot];
    arr[pivot] = arr[end];
    arr[end] = temp;
    return end;
}

void quicksort(int lb, int ub){
    if(lb<ub){
        int loc = partition(lb,ub);
        quicksort(lb,loc-1);
        quicksort(loc+1,ub);       
    }
}

void display(){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){

    quicksort(0,n-1);
    display();
    return 0;
}
