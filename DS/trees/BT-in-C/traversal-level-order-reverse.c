// Iterative Queue based C program to do level order traversal of Binary tree in reverse order
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_Q_SIZE 250 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* frunction prototypes */
struct node** createQueue(int *, int *); 
void enQueue(struct node **, int *, struct node *); 
struct node *deQueue(struct node **, int *); 
struct node** createStack(int *);
void push(struct node **,int *,struct node *);
void printStack(struct node **, int *);
struct node* pop(struct node **,int *);
  
/* Given a binary tree, print its nodes in level order 
   using array for implementing queue */
void printReverseLevelOrder(struct node* root) 
{ 
    int rear, front,top=0; 
    struct node **queue = createQueue(&front, &rear); 
    struct node *temp_node = root,*temp_node1; 
    int stack[20];
  
    while (temp_node) 
    { 
        // printf("%d ", temp_node->data); 
        stack[top++]=temp_node->data;
        /*Enqueue right child */
        if (temp_node->right) 
            enQueue(queue, &rear, temp_node->right);
        /*Enqueue left child */
        if (temp_node->left) 
            enQueue(queue, &rear, temp_node->left); 
  
         
  
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
        // printf("%d ",temp_node->data);
        // stack[top++]=temp_node->data;
    } 
    while(top--){
        printf("%d ",stack[top]);
    }
} 
  
/*UTILITY FUNCTIONS*/



// void printStack(struct node** stack,int *top){
//     *top = *top-1;
//     while(*top){
//         printf("%d",stack[*top]->data);
//         *top--;
//     }
// }
struct node** createQueue(int *front, int *rear) 
{ 
    struct node **queue = 
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE); 
  
    *front = *rear = 0; 
    return queue; 
} 
// void push(struct node **stack,int *top,int data){
//     stack[*top]=data;
//     // printf("%d ",stack[top]->data);
//     (*top)++;
//     // return top;
// }  
void enQueue(struct node **queue, int *rear, struct node *new_node) 
{ 
    queue[*rear] = new_node; 
    (*rear)++; 
} 
 
struct node *deQueue(struct node **queue, int *front) 
{ 
    (*front)++; 
    return queue[*front - 1]; 
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
    printf("Reverse Level Order traversal of binary tree is:\n"); 
    printReverseLevelOrder(root);     
    return 0; 
}
