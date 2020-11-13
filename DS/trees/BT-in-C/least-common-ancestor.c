// C program to find the least common ancestor of two nodes in a given binary tree.
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
NODE *leastCommonAncestor(NODE *root,NODE *a,NODE *b){
    NODE *left,*right;
    if(root==NULL)
        return NULL;
    if(root==a || root==b)
        return root;
    left=leastCommonAncestor(root->left,a,b);
    right=leastCommonAncestor(root->right,a,b);
    if(left&&right)
        return root;
    else
    {
        return (left?left:right);
    }  
}
int main(){
    NODE *root = NULL,*temp,*a,*b;
    // int choice;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    a=insertleft(root->left,4);
    insertright(root->left,5);
    b=insertleft(root->right,6);
    insertright(root->right,7);
    temp=leastCommonAncestor(root,a,b);
    printf("Least common ancestor of the given two nodes is: %d\n",temp->data);
    return 0;
}