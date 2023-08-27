#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NodeType;
NodeType *head=NULL, *newnode, *temp;

void insert(int item){
    newnode = (NodeType*)malloc(sizeof(NodeType));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head==NULL){
        head = temp = newnode;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("\n%d is inserted.\n",item);
}

void Delete(){
    temp = head;
    if(head==NULL){
        printf("\nThe list is Empty!!\n");
    }
    else{
        head = temp->next;
        head->prev = NULL;
        printf("\n%d is deleted.\n",temp->data);
        free(temp);
    }
}

void display(){
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
    Delete();
    display();
    return 0;
}