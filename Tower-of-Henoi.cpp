#include<stdio.h>

void toh(int n, char from, char to, char aux){
    if(n==1){
        printf("\ndisc %d is moved from %c to %c\n",n,from,to);
        return;
    }
    toh(n-1,from,aux,to);
    printf("\ndisc %d is moved from %c to %c\n",n,from,to);
    toh(n-1,aux,to,from);
}

int main(){

    int n;
    printf("Enter no. of disks: ");
    scanf("%d",&n);

    toh(n,'A','B','C');

    return 0;
}