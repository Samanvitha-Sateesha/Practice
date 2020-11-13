// Iterative Queue based C program to do level order traversal 
// of Binary Tree 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_Q_SIZE 500 
int front,rear;  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* frunction prototypes */
struct node** createQueue(); 
void enQueue(struct node **, struct node *); 
struct node *deQueue(struct node **); 
  
/* Given a binary tree, print its nodes in level order 
   using array for implementing queue */
void printLevelOrder(struct node* root) 
{ 
    // int rear=0, front=0; 
    struct node **queue = createQueue(); 
    struct node *temp_node = root; 
    enQueue(queue,temp_node);
    while (temp_node) 
    { 
        temp_node = deQueue(queue);
        printf("%d ", temp_node->data); 
  
        /*Enqueue left child */
        if (temp_node->left) 
            enQueue(queue, temp_node->left); 
  
        /*Enqueue right child */
        if (temp_node->right) 
            enQueue(queue,  temp_node->right); 
  
        /*Dequeue node and make it temp_node*/
        // temp_node = deQueue(queue, &front); 
    } 
} 
  
/*UTILITY FUNCTIONS*/
struct node** createQueue() 
{ 
    struct node **queue = 
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE); 
  
    front = rear = 0; 
    return queue; 
} 
  
void enQueue(struct node **queue,struct node *new_node) 
{ 
    queue[rear] = new_node; 
    (rear)++; 
} 
  
struct node *deQueue(struct node **queue) 
{ 
    (front)++; 
    return queue[front - 1]; 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    printf("Level Order traversal of binary tree is:\n"); 
    printLevelOrder(root); 
  
    return 0; 
}
