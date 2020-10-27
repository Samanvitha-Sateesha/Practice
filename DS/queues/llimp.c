// A C program to demonstrate linked list based implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list (LL) node to store a queue entry 
struct QNode { 
    int data; 
    struct QNode* link; 
}; 
  
// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct Queue { 
    struct QNode *front, *rear; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(int num) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->data = num; 
    temp->link = NULL; 
    return temp; 
} 
  
// A utility function to create an empty queue 
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
// The function to add a key k to q 
void enQueue(struct Queue* q, int k) 
{ 
    // Create a new LL node 
    struct QNode* temp = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->link = temp; 
    q->rear = temp; 
} 
  
// Function to remove a key from given queue q 
int deQueue(struct Queue* q) 
{ 
    int data;
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
    {
        printf("Empty queue");
        return -1; 
    }
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->front; 
    data = temp->data;
    q->front = q->front->link; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
        q->rear = NULL; 
    free(temp); 
    return data;
} 
void display(struct Queue *q){
    struct QNode* temp = q->front;
    printf("Contents of the queue are:\n");
    while(temp!=q->rear){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d ",temp->data); 
    printf("\n");
}  
// Driver Program to test anove functions 
int main() 
{ 
    struct Queue* q = createQueue();
        int num,choice;
    while(1){
        printf("Choose the operation you want to perform\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Top\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the number you want to push\n");
            scanf("%d",&num);
            enQueue(q, num);
            break;
        case 2:  printf("%d dequeued\n",deQueue(q));
            break;
        case 3: display(q);
            break;
        case 4: printf("Queue Front : %d \n", q->front->data); 
                printf("Queue Rear : %d", q->rear->data);
            break;
        default:exit(0);
        }
    }       
    return 0; 
}