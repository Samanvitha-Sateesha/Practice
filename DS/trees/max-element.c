#include<stdio.h>
#include<stdlib.h>
struct BinaryTreeNode{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct BinaryTreeNode NODE;
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
int maxElement(NODE *root){
    int leftMax,rightMax,root_val,max=-1;
    if(root!=NULL){
        root_val = root->data;
        leftMax = maxElement(root->left);
        rightMax = maxElement(root->right);
        if(leftMax>rightMax)
            max=leftMax;
        else
        {
            max = rightMax;
        }
            
        if(root_val>max)
            max=root_val;  
    }
    return max;
}
int main(){
    NODE *root = NULL;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    printf("Maximum element in the tree is %d \n",maxElement(root));
    return 0;
}    