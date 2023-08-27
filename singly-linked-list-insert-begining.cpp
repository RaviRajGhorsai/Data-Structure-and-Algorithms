#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NodeType;
NodeType *head=NULL, *newnode, *temp;

void insert(int item){
    newnode = (NodeType*)malloc(sizeof(NodeType));
    newnode->data = item;
    newnode->next = head;
    head = newnode;
    printf("%d is inserted.\n",item);
}

void Delete(){
    if(head==NULL){
        printf("No. elements to delete!!\n");
    }
    else{
        temp=head;
        head = head->next;
        printf("\n%d is deleted.\n",temp->data);
        free(temp);
    }
}

void display(){
    temp=head;
    while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
    }
}

int main(){

    insert(10);
    insert(20);
    insert(30);
    display();
    Delete();
    display();
    return 0;
}