#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NodeType;
NodeType *head=NULL, *newnode, *temp, *p;

int size;
void create(int size){

    for(int i=1;i<size;i++){
        newnode = (NodeType*)malloc(sizeof(NodeType));
        
        newnode->prev = NULL;
        newnode->data = i;
        if(head==NULL){
            newnode->next = NULL;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
        }
        head = newnode;
    }
}

void insert(int item, int pos){
    int i=1;
    temp = head;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    newnode = (NodeType*)malloc(sizeof(NodeType));
    newnode->data = item;

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    printf("\n%d is inserted at position %d\n",item,pos);
}

void Delete(int pos){
    int i=1;
    temp = head;
    if(head==NULL){
        printf("\nList is empty!!\n");
        return;
    }
    else{
        while(i<pos-1){
        temp = temp->next;
        i++;
    }
        p = temp->next;
        temp->next = p->next;
        p->next->prev = temp;
        printf("\n%d is deleted from position %d.\n",p->data,pos);
        free(p);
    }
}

void display(){
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp =temp->next;
    }
}

int main(){
    create(5);
    display();
    insert(20,3);
    insert(30,5);
    display();
    Delete(4);
    display();
    return 0;
}