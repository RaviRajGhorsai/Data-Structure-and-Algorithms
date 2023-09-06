#include<stdio.h>

void mergesort(int a[],int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void merge(int a[], int lb, int mid, int ub){
    int i=lb, k=lb;
    int j=mid+1;
    int b[lb+ub];
    while(i<=mid && j<ub){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
}

int main(){
    int n=7, lb=0, ub=7;
    int a[n-1] = {38,27,43,3,9,82,10};
    mergesort(a,lb,ub);

    return 0;
}