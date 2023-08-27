#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NodeType;
NodeType *head=NULL, *newnode, *temp, *tail;

void insert(int item){
    newnode = (NodeType*)malloc(sizeof(NodeType));
    newnode->data = item;

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    printf("\n%d is inserted.\n",item);
}

void Delete(){
    if(head==NULL){
        printf("\nEmpty list!!\n");
    }
    else{
        if(head->next==NULL){
            temp = head;
            head = tail = NULL;
            printf("\n%d is deleted.\n",temp->data);
            free(temp);
        }
        else{
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            printf("\n%d is deleted.\n",temp->data);
            free(temp);
        }

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