// Given inorder and preorder travel sequences of a Binary Tree, this code builds that binary tree.
#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *buildBinaryTree(char *A, int *i){
    NODE *new;
    new = (NODE *)malloc(sizeof(NODE));
       
    new->data = A[*i];
    new->left = new->right = NULL;
    if(A==NULL){
        free(new);
        return NULL;
    }
    if(A[*i]== 'L')
        return new;
    *i=*i+1;
    new->left = buildBinaryTree(A,i);
    *i=*i+1;
    new->right = buildBinaryTree(A,i);
    return new;
}
void postorder(NODE *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}
int main(){
    NODE *root;
    char *A;
    int i=0,len;
    printf("Enter the length:");
    scanf("%d",&len);
    A=(char *)malloc(sizeof(char)*len);
    printf("Enter the sequence\n");
    scanf("%s",A);
    root = buildBinaryTree(A,&i);
    printf("Post Order Traversal of the given Binary Tree is:\n");
    postorder(root);
    return 0;
}