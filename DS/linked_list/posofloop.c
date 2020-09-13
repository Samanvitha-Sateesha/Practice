// This program is to find out if a linked list is NULL terminated or it contains a loop.
// The program is also referred to as snake-snail problem
// Further the program is extended to find out the position of the node from which the loo[p begins 
// if linkedlist contains a loop.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}NODE;
// struct header{
//     int data;
//     struct header *ptr;
//     struct header *last;
// }*head;
NODE *head, *rear = NULL;
void initilise(){
    head = (NODE *)malloc(sizeof(NODE));
    head->data = 0;
    head->ptr = NULL;
    // head->last = rear;
}
NODE* insertbeg(int num){
    NODE* new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    if (head->ptr == NULL){    
        new->ptr = new;
        head->ptr = new;
        rear = new;
        head->data++;
        return new;
    }
    new->ptr = head->ptr;
    head->ptr = new;
    rear->ptr=new;
    head->data++;
    return new;
}
NODE* insertend(int num){
    NODE* new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    if (head->ptr == NULL){    
        new->ptr = new;
        head->ptr = new;
        rear = new;
        head->data++;
        return new;
    }
    rear->ptr = new;
    new->ptr = head->ptr;
    rear = new;     
    head->data++;
    return new;
}

void display(){
    NODE* temp = head->ptr;
    if(head->ptr == NULL){
        printf("Empty list\n");
        return;
    }
    printf("Contents of the list are:\n");
    for(int i=0;i<head->data;i++){
        printf("%d\n",temp->data);
        temp = temp->ptr;    
    }
    printf("End of List\n");
}
int doesllhasloop(){
    NODE *slowptr = head;
    NODE *fastptr = head;
    int loopexists = 0; // To find the position of the node from which loop begins.
    while(slowptr && fastptr && fastptr->ptr){
        slowptr = slowptr->ptr;
        fastptr = fastptr->ptr->ptr;
        if(slowptr == fastptr){
            loopexists = 1;    
            break;
        }        
    }
    if(loopexists){
        slowptr = head;
        if(slowptr == head && fastptr == head){
            return slowptr->data;
        }
        while (slowptr != fastptr )
        {
            slowptr = slowptr->ptr;
            fastptr = fastptr->ptr;
        }
        return slowptr->data;   
    }
    return 0;  //If there is no loop
}
int main(){
    int res;
    initilise();
    printf("Linked list initialised\n");
    insertbeg(10);
    insertbeg(20);
    insertbeg(30);
    insertend(4);
    display();
    res = doesllhasloop();
    if(res ){
        printf("Loop exists and the value in the node from which loop starts is:%d\n",res);
    }
    else
    {
        printf("Loop doesnt exist\n");
    } 
    return 0;
}    