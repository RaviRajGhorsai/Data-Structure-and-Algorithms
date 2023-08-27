#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NodeType;
NodeType *head = NULL, *temp, *newnode, *tail;

void insert(int item){
    newnode = (NodeType*)malloc(sizeof(NodeType));
    newnode->data = item;
    if(head==NULL){
        newnode->next = NULL;
        head = tail = newnode;
    }
    else{
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
}

void Delete(){
    if(head == NULL){
        printf("No elements to delete!!\n");
    }
    else if(head->next == NULL){
        temp = head;
        head = tail = NULL;
        printf("\n%d is deleted.\n",temp->data);
        free(temp);
    }
    else{
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        tail = temp;
        printf("\n%d is deleted.\n",temp->next->data);
        temp->next = NULL;
        free(temp->next);

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