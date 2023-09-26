#include<stdio.h>
#include<stdlib.h>
#define m 10
int htable[m];

void init(){
    for(int i=0;i<m;i++){
        htable[i]=0;
    }
}

int hashfunction(int kvalue){
    int hash = kvalue%m;
    return hash;
}

void insert(int kvalue){
    int hindex = hashfunction(kvalue);
    if(htable[hindex]==0){
        htable[hindex] = kvalue;
        printf("\n\n%d is inserted.\n",kvalue);
    }
    else{
        printf("Collision occured!!\n");

        while(htable[hindex]!=0){
            hindex++;
        }
        if(hindex<m){
            htable[hindex] = kvalue;
            printf("\n\n%d is inserted.\n",kvalue);
        }
        else{
            printf("Slot not found!!!\n");
        }
    }
}

void search(int kvalue){
    int hindex = hashfunction(kvalue);
    if(htable[hindex] == kvalue){
        printf("\nElement found index %d.\n",hindex);
    }
    else{
        while(hindex<m){
            hindex++;
            if(htable[hindex] == kvalue){
                printf("\nElement found index %d.\n",hindex);
                return;
            } 
        }
        printf("Element not found!!\n");
    }
}

void display(){
    for(int i=0;i<m;i++){
        printf("%d ",htable[i]);
    }
    printf("\n\n");
}

int main(){

    init();

    int choice,hvalue;

    printf("1.Insert\t2.Search\t3.Display\t4.Exit\n\n");

    while(choice!=4){
        printf("Enter choice:  ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to insert:\n");
                scanf("%d",&hvalue);
                insert(hvalue);
                break;
            case 2:
                printf("\nEnter the value to search: \n");
                scanf("%d",&hvalue);
                search(hvalue);
                break;
            case 3:
                printf("\nThe hash table values are:\n");
                display();
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    }

    return 0;
}