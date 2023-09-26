#include<stdio.h>

void binarysearch(int arr[], int key, int lb, int ub){
    int mid = (lb+ub)/2;

    if(key == arr[mid]){
        printf("Element found at index %d",mid);
        return;
    }
    else if(key<arr[mid]){
        return binarysearch(arr,key,0,mid-1);
    }
    else{
        return binarysearch(arr,key,mid+1,ub);
    }
}

int main(){

    int n=10,key;
    int arr[n] = {1,2,5,8,10,14,16,25,30,34};

    printf("Enter the key value:\n");
    scanf("%d",&key);

    binarysearch(arr,key,0,n-1);

    return 0;
}