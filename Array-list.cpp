#include<stdio.h>

    int pos=0;
    int n=5;
 
    int last_index=-1;

void insert(int item){
 
   int list[n];
    if(last_index==n-1){
        printf("List is full !!\n");
        return;
    }
    if(pos<0 || pos>last_index+1){
        printf("Invalid position.\n");
        return;
    }

    list[pos+1]=list[pos];
    list[pos]=item;
    last_index++;

    printf("The item %d has been inserted in %d position.\n",item,last_index);
    pos++;
    

}

void delete_list_front(){
    int item;
    int list[n];
    if(last_index==-1){
        printf("The list is empty !!\n");
        return;
    }
    if(pos<0 || pos>last_index){
        printf("Invalid Position\n");
        return;
    }

    item=list[last_index];
    printf("The item %d is deleted from %d\n",item,last_index);
    
    last_index--;
}

int main(){

insert(1);
insert(2);
insert(3);
insert(4);

delete_list_front();

    return 0;
}