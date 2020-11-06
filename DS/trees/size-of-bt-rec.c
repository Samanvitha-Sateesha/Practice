// Program to compute the size of the Binary Tree using recursive function calls.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE* createnode(int num){
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->data = num;
    new->left = new->right = NULL;
    return new;
}
NODE* insertleft(NODE *root, int num){
    root->left=createnode(num);
    return root->left;
}
NODE* insertright(NODE *root, int num){
    root->right=createnode(num);
    return root->right;
}
int sizeOfBT(NODE *root){
    if(root==NULL)
        return 0;
    else
    {
        return(sizeOfBT(root->left)+1+sizeOfBT(root->right));
    }
}
int main(){
    NODE *root = NULL;
    int choice;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    printf("Size of the given binary tree is:\n",sizeOfBT(root));
    return 0;
}