// This program is to find out if a linked list is NULL terminated or it contains a loop.
// The program is also referred to as snake-snail problem
// Further the program is extended to find out the length of the loop, if linkedlist contains a loop.

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}NODE;
NODE *head, *rear = NULL;
void initilise(){
    head = (NODE *)malloc(sizeof(NODE));
    head->data = 0;
    head->ptr = NULL;
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
int looplength(){
    NODE *slowptr = head;
    NODE *fastptr = head;
    int loopexists = 0, counter = 0; // To find the position of the node from which loop begins.
    while(slowptr && fastptr && fastptr->ptr){
        slowptr = slowptr->ptr;
        fastptr = fastptr->ptr->ptr;
        if(slowptr == fastptr){
            loopexists = 1;    
            break;
        }        
    }
    if(loopexists){
        fastptr = fastptr->ptr;
        counter++;                     //increasing the count when first node after the loopnode is visited.
        while (slowptr != fastptr)
        {
            fastptr = fastptr->ptr;
            counter++;
        }
        return counter;    //returns the length of the loop
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
    res = looplength();
    printf("Length of the loop is %d\n",res);
    return 0;
}    