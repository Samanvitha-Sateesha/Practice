// Iterative Queue based C program to count the number of leaf nodes in the binary tree
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

/* Given a binary tree, count the number of leaf nodes and return the count*/
int numOfLeafNodesInBT(struct node *root)
{
    if (!root)
        return 0;
    int rear = -1, front = -1, count = 0;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;
    enQueue(queue, &rear, root);
    while (isEmptyQueue(&front, &rear) == 0)
    {
        /*Dequeue node and make it temp_node */
        temp_node = deQueue(queue, &front);
        if (!temp_node->left && !temp_node->right)
            count++;
        // printf("%d ", temp_node->data);
            /*Enqueue left child */
            if (temp_node->left)
                enQueue(queue, &rear, temp_node->left);

            /*Enqueue right child */
            if (temp_node->right)
                enQueue(queue, &rear, temp_node->right);
    }
    return count;
}

/*UTILITY FUNCTIONS*/
struct node **createQueue(int *front, int *rear)
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

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node *newNode(int data)
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
    struct node *root = newNode(1);
    // int height=0;
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Number of leaf nodes in binary tree is: %d\n", numOfLeafNodesInBT(root));
    return 0;
}
