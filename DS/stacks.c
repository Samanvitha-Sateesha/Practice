//  Implementation of basic operations of a stack -- push,pop,peek

#include<stdio.h>
#include<stdlib.h>
int top = -1;
int stk[10];
void push(int num){
    if(top==10){
        printf("Stack full\n");
        return;
    }
    top++;
    stk[top]=num;
    printf("Element pushed\n");
}
void pop(){
    if(top==-1){
        printf("Stack empty\n");
        return;
    }
    printf("%d is being popped out",stk[top--]);
}
int peek(){
    if(top==-1){
        printf("Stack empty\n");
        return -1;
    }
    return stk[top];
}
int main(){
    int choice,num;
    while(1){
        printf("\n\nEnter your choice:\n1.Push\n2.Pop\n3.Peek\nAny other number to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the number you want to Push:");
               scanf("%d",&num);
               push(num); 
            break;
        case 2: pop();
            break;
        case 3: printf("Top element of the stack is: %d",peek()); 
            break;   
        default:
            exit(0);
        }
    }
    return 0;
}