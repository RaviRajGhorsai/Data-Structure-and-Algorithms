#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=8;
    int arr[n] = {33, 31, 40, 8, 12, 17, 25, 42};

    for(int gap=n/2;gap>=1;gap/=2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0 && arr[i+gap]<arr[i];i--){
                
                    int temp = arr[i+gap];
                    arr[i+gap] = arr[i];
                    arr[i] = temp;
                
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}