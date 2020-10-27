#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -256
struct Snode{
    int data;
    struct node *link;
};
typedef struct Snode NODE;
void push(NODE **top,int num){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if(!temp){
        printf("Memory Error");
        return NULL;
    }    
    temp->data = num;
    temp->link = *top;
    *top= temp;
    printf("Pushed\n");
}
int isEmptyStack(NODE *top){
    if(top==NULL)
        return 1;
    else
    {
        return 0;
    }
}
int pop(NODE **top){
    NODE* temp;
    int num;
    if(isEmptyStack(top)){
        printf("Empty Stack, cannot pop\n");
        return INT_MIN;
    }
    temp = *top;
    *top = (*top)->link;
    num= temp->data;
    temp->link = NULL;
    free(temp);
    return num;
}
int topOfStack(NODE **top){
    if(isEmptyStack(top) == 1){
        printf("Stack is empty\n");
        // return INT_MIN;
    }
    return (*top)->data;
}
void display(NODE *top){
    NODE *temp=top;
    printf("Stack is:\n");
    while(temp){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}
int main(){
    NODE *top = NULL;
    int num,choice;
    while(1){
        printf("Choose the operation you want to perform\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Top\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the number you want to push\n");
            scanf("%d",&num);
            push(&top,num);
            break;
        case 2: printf("%d popped\n",pop(&top));
            break;
        case 3: display(top);
            break;
        case 4: printf("%d is the element at the top of the stack\n",topOfStack(&top));
            break;
        default:exit(0);
        }
    }
    return 0;
}