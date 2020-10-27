#include<stdio.h>
#include<stdlib.h>
struct BinaryTreeNode{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct BinaryTreeNode BTNODE;
struct QNode { 
    int data; 
    struct QNode* link; 
}; 
struct Queue { 
    struct QNode *front, *rear; 
}; 
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
struct Queue* Q;
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
BTNODE* deQueue(struct Queue* q) 
{ 
    int data;
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
    {
        printf("Empty queue");
        return -1; 
    }
    // Store previous front and move front one node ahead 
    struct BTNODE* temp = q->front; 
    // data = temp->data;
    q->front = q->front->link; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
        q->rear = NULL; 
    return temp; 
    
}
BTNODE* createnode(int num){
    BTNODE *new = (BTNODE*)malloc(sizeof(BTNODE));
    new->data = num;
    new->left = new->right = NULL;
    return new;
}
BTNODE* insertleft(BTNODE *root, int num){
    root->left=createnode(num);
    return root->left;
}
BTNODE* insertright(BTNODE *root, int num){
    root->right=createnode(num);
    return root->right;
}
void levelOrderTraversal(BTNODE *root){
    BTNODE *temp,*templ,*tempr;
    printf("Result of Level Order Traversal is:\n");
    Q=createQueue();
    if(!root)
        return;
    enQueue(Q,root->data);
    while (Q->front != NULL)
    {
        temp = deQueue(Q);
        printf("%d ",temp->data);
        if(temp->left){
            templ=temp->left;
            int datal = templ->data;
            enQueue(Q,datal);
            // enQueue(Q,temp->left);
        }   
        if(temp->right){
            tempr=temp->right;
            int datar = tempr->data;
            enQueue(Q,datar);
        }
    }   
}
int main(){
    BTNODE *root = NULL;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);    
    levelOrderTraversal(root);
    return 0;
}    