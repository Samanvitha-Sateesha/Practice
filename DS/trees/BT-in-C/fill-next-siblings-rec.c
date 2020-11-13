// Recursive C program to fill next sibling pointers of a binary tree. 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *nextSibling;
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
void fillNextSiblings(NODE *root){
    if(!root)
        return;
    if(root->left)
        root->left->nextSibling = root->right;
    if(root->right)
        root->right->nextSibling = (root->nextSibling)?root->nextSibling->left:NULL;
    fillNextSiblings(root->left);
    fillNextSiblings(root->right);
}
int main(){
    NODE *root = NULL;
    // int choice;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    fillNextSiblings(root);
    printf("Completed!\n");
    return 0;
}