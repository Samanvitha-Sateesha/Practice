// C program to convert the given binary tree to its mirror.
// Mirror of a tree is another tree with left and right children of all non-leaf nodes interchanged.
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
NODE *mirrorOfBT(NODE *root){
    NODE *temp;
    if(root){
        mirrorOfBT(root->left);
        mirrorOfBT(root->right);
        // Now, we will be in that node whose children are leaf nodes. Therefore, swap the pointers.
        temp=root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
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
    root = mirrorOfBT(root);
    printf("Completed!\n");
    return 0;
}