#include<stdio.h>
#define n 10


void search(int arr[], int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("Element is found at index %d.\n",i); 
            return;         
        }
    }
    printf("Element not found!!!\n");
}

int main(){

    int key;
    int arr[n] = {1,2,5,8,10,14,16,25,30,34};

    printf("Enter the element to be searched:\n");
    scanf("%d",&key);

    search(arr,key);

    return 0;
}