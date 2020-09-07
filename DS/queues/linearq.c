#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int enqueue(int arr[],int num,int k){
    if(rear == k-1){
        printf("Queue is full\n");
        return -1;
    }
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[rear]=num;
    }
    else{
        rear++;
        arr[rear]=num;
    }
    printf("%d enqueued\n",num);
    return arr;
}
void dequeue(int arr[]){
    if(front == -1 || front > rear){
        printf("Queue is empty and element cannot be dequeued\n");
    }
    else
    {
        printf("%d dequeued\n",arr[front]);
        front++;
    }
}
int ffront(int arr[]){
    printf("%d\n",arr[front]);
    return arr[front];
}
int frear(int arr[]){
    return arr[rear];
}
int main(){
    
    int k, arr[k],ch,num;
    printf("Enter the size of the Queue\n");
    scanf("%d",&k);
    while(1){
        printf("\nChoose the operation:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Front\n4.Rear\nAny other option to exit\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter the element to be enqueued\n");
                scanf("%d",&num);
                enqueue(arr,num,k);
            break;
        case 2: dequeue(arr);
            break;
        case 3: printf("Element present in the front of the queue is %d\n",ffront(arr));
            break;
        case 4: printf("Element present in the rear end of the queue is %d\n",frear(arr));
            break;    
        default: exit(0);
        }
    }
}