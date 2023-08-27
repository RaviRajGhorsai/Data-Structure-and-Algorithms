#include<stdio.h>

int main(){
    int n=5;
    int arr[n] = {6,0,3,5,7};

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("%d ",arr[i]);
    }
    return 0;
}