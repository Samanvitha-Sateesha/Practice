// C program to find out if the given two Binary trees are mirrors of each other.
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
int areBTMirrors(NODE *root1,NODE *root2){
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    if(root1->data != root2->data)
        return 0;
    return (areBTMirrors(root1->left,root2->right) && areBTMirrors(root1->right,root2->left));    
}
  
int main(){
    NODE *root1 = NULL, *root2=NULL;
    // int choice;
    root1=createnode(1);
    insertleft(root1,2);
    insertright(root1,3);
    insertleft(root1->left,4);
    insertright(root1->left,5);
    root2=createnode(1);
    insertright(root2,2);
    insertleft(root2,3);
    insertleft(root2->right,5);
    insertright(root2->right,4);
    (areBTMirrors(root1,root2)==1)?printf("The given Binary trees are mirrors\n"):printf("The given binary trees are not mirrors\n");
    return 0;
}