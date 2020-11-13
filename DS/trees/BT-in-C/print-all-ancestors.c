// This C prpogram prints all the ancestor node's data of a given node.
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
// Here, the return type of the function is int because we are uisng the logical OR operator and
// we want the data to be printed of any one among the given operands is true.
int printAllAncestors(NODE *root,NODE *given){
    if(root==NULL)
        return 0;
    if(root->left == given || root->right == given || printAllAncestors(root->left,given) || printAllAncestors(root->right,given)){
        printf("%d ",root->data);
        return 1;
    }    
    return 0;
}
int main(){
    NODE *root = NULL,*a;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    a=insertright(root->right,7);
    printAllAncestors(root,a);
    return 0;
}    