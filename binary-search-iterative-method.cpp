#include<stdio.h>

void binarysearch(int arr[], int key, int lb, int ub){
     while(ub>lb){
        int mid = (lb+ub)/2;
        if(key == arr[mid]){
            printf("key found at index %d.\n",mid);
            return;
        }
        else if(key<arr[mid]){
            ub=mid-1;
            lb=0;
        }
        else{
            lb = mid+1;
        }
    }
    printf("element not found!!");
}

int main(){

    int n=10;
    int arr[10] = {1,2,5,8,10,14,16,25,30,34};

    int key;

    printf("Enter the key value: \n");
    scanf("%d",&key);
   
    binarysearch(arr,key,0,n-1);
    
    return 0;
}