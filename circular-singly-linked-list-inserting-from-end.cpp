#include<stdio.h>       /*Delete function is not working as required*/
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NodeType;
NodeType *head, *tail, *temp, *newnode, *temp1;

void insert(int item){
    newnode = (NodeType*)malloc(sizeof(NodeType));
    newnode->data = item;
    newnode->next = NULL;

    if(head==NULL){
        head = tail = newnode;
        tail->next = head;
    }
    else{
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    printf("\n%d is inserted.\n",item);
}

void Delete(){
    temp = head;
    if(head==NULL){
        printf("\nEmpty List!!\n");
        return;
    }
    else if(temp->next == temp){
        tail = NULL;
        free(temp);
    }
    else{
        while(temp->next!=tail->next){
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = tail->next;
        tail = temp1;
        printf("\n%d is deleted.\n",temp->data);
        free(temp);
        
    }
}

void display(){
    temp = head;
    while(temp->next != tail->next){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();
    Delete();
    display();
    return 0;
}