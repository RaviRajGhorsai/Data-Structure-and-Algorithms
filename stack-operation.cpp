#include<stdio.h>
#include<stdlib.h>
#define size 5

void push(int stack[],int item);
int pop(int stack[]);
void findtop(int stack[]);
void display(int stack[]);

int tos=-1;

int main(){

    int stack[size];
    int item,n;

    while(1){
         
    printf("\n\nChoose any of the following: \n");
    printf("1.Push\n2.Pop\n3.Find Top\n4.Display\n5.Exit\n");
    scanf("%d",&n);

    switch(n){
        case 1:
            printf("\nEnter the item to be inserted:\n");
            scanf("%d",&item);
            push(stack,item);
            break;

        case 2:
            pop(stack);
            break;
        case 3:
            findtop(stack);
            break;
        case 4:
            display(stack);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid entry!!");
            break;
    }

    }

    return 0;
}

void push(int stack[],int item){
    tos++;
    if(tos>=size){
        printf("\nStack overflow, please remove some item!!\n");
    }
    else{
        stack[tos]=item;
    }
}

int pop(int stack[]){
    int item;
    if(tos==-1){
        printf("Stack empty,please enter some items!!\n");
    }
    else{
        item=stack[tos];
        tos--;
    }
    return item;
}

void findtop(int stack[]){
    printf("\nitem in top of stack is: %d\n",stack[tos]);
}

void display(int stack[]){
    int i;
    printf("\n");
    for(i=0;i<=tos;i++){
        printf("%d\t ",stack[i]);
    }
}

