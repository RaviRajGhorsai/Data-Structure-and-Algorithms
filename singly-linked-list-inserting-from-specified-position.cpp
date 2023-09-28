#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};
typedef struct node NodeType;
NodeType *head=NULL, *newnode, *temp, *p;

int size;
void create(){
    printf("\nEnter size of list: ");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        newnode = (NodeType*)malloc(sizeof(NodeType));
        newnode->data = i;
        newnode->next = head;
        head = newnode;
    }
}

void insert(int item, int pos){
    int i=1;
    // printf("\nEnter the position to insert the list: ");
    // scanf("%d",&pos);
    if(pos>size){
        printf("\nInvalid Position!!\n");
    }
    else{
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode = (NodeType*)malloc(sizeof(NodeType));
        size++;
        newnode->data = item;
        newnode->next = temp->next;
        temp->next = newnode;
        printf("\n%d is inserted at position %d\n",item,pos);
    }
}

void Delete(int pos){
    int  i=1;
    // printf("Enter the position to delete the list: ");
    // scanf("%d",pos);
    if(pos>size){
        printf("\nInvalid Position!!\n");
    }
    else{
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        p = temp->next;
        temp->next = p->next;
        printf("\n%d is deleted at pos %d\n",p->data,pos);
        free(p);
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
    create();
    display();
    insert(20,2);
    insert(30,4);
    display();
    Delete(3);
    display();
    return 0;
}