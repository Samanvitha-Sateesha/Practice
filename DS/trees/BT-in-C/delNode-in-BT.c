// Iterative Queue based C program to delete a particular node in binary tree given its value
#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* frunction prototypes */
struct node **createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);
int isEmptyQueue(int *, int *);

/* Given a binary tree, delete a node with given value and print the remaining tree.*/
void deleteANodeInBT(struct node *root,int delVal)
{
    if (!root)
        return ;
    int rear = -1, front = -1;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;
    struct node *del_node;
    enQueue(queue, &rear, root);
    while (isEmptyQueue(&front, &rear) == 0)
    {
        /*Dequeue node and make it temp_node */
        temp_node = deQueue(queue, &front);
        if(temp_node->data==delVal)
            del_node = temp_node;
        // printf("%d ", temp_node->data);
        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
    }
    del_node->data = temp_node->data;
    free(temp_node);
    printf("Deleted!\n");
    struct node **queue1 = createQueue(&front, &rear);
    struct node *temp_node1 = root;
    //  enQueue(queue1, &rear, temp_node1);
    do
    {
        /*Dequeue node and make it temp_node */
        /*Enqueue left child */
        if (temp_node1->left)
            enQueue(queue1, &rear, temp_node1->left);
        /*Enqueue right child */
        if (temp_node1->right)
            enQueue(queue1, &rear, temp_node1->right);
        printf("%d ", temp_node1->data);
        temp_node1 = deQueue(queue1, &front);
            
    }while (isEmptyQueue(&front,&rear)==0);
}

/*UTILITY FUNCTIONS*/
struct node **
createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node *) * MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

int isEmptyQueue(int *front, int *rear)
{
    if (*front >= *rear)
    {
        return 1;
    }
    else
        return 0;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct node *
deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node *
newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/* Driver program to test above functions*/
int main()
{
    int delVal;
    struct node *root = newNode(1);
    // int height=0;
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Enter the value u want to delete from Binary Tree\n");
    scanf("%d",&delVal);
    deleteANodeInBT(root,delVal);
    return 0;
}
