// Program to compute the height of the Binary Tree using recursive function calls.
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
int heightOfBinaryTree(NODE *root){
    int leftheight,rightheight;
    if(root==NULL)
        return 0;
    leftheight=heightOfBinaryTree(root->left);
    rightheight=heightOfBinaryTree(root->right);
    if(leftheight>rightheight)
        return (leftheight+1);
    return (rightheight+1);        
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
    printf("Height of the given binary tree is:%d\n",heightOfBinaryTree(root));   
    return 0;
}