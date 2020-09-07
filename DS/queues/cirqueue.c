#include<stdio.h>
#include<stdlib.h>
#define QUE_SIZE 5
int count=0,front=0,rear=-1;

void enqueue(int que[],int num){
    if(count == QUE_SIZE){
        printf("Queue is full\n");
        return;
    }
    rear = (rear+1)%QUE_SIZE;
    que[rear]=num;
    count++;
    printf("%d enqueued\n",num);
}
void dequeue(int que[]){
    if(count == 0){
        printf("Empty Queue\n");
        return;
    }
    front=(front+1)%QUE_SIZE;
    count--;
    printf("Dequeue Successful\n");
}
void display(int que[]){
    int i=front,j;
    for(j=0;j<count;j++){
        printf("%d\n",que[i]);
        i=(i+1)%QUE_SIZE;
    }
}
int main(){
    int que[QUE_SIZE];
    int ch,num;
    while(1){
        printf("\nChoose the operation:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\nAny other option to exit\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter the element to be enqueued\n");
                scanf("%d",&num);
                enqueue(que,num);
            break;
        case 2: dequeue(que);
            break;
        case 3: printf("Contents of the queue are:\n");
                display(que);
            break;    
        default: exit(0);
        }
    }
}