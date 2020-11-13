// Given inorder and preorder travel sequences of a Binary Tree, this code builds that binary tree.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *buildBinaryTree(int inorder[],int preorder[],int inorderStart,int inorderEnd){
    static int preorderIndex=0;
    int inorderIndex;
    NODE *new;
    if(inorderStart>inorderEnd)
        return NULL;
    new = (NODE *)malloc(sizeof(NODE));
    if(new == NULL){
        printf("Memory Error!\n");
        return NULL;
    }    
    new->data = preorder[preorderIndex];
    preorderIndex++;
    if(inorderStart==inorderEnd)
        return new;
    inorderIndex=Search(inorder,inorderStart,inorderEnd,new->data);
    if(inorderIndex==-1){
        printf("Travel sequences incorrect!\n");
        return NULL;
    }
    new->left = buildBinaryTree(inorder,preorder,inorderStart,inorderIndex-1);
    new->right = buildBinaryTree(inorder,preorder,inorderIndex+1,inorderEnd);
    return new;
}
int Search(int inoder[],int inorderStart,int inorderEnd,int num){
    int i;
    for(i=inorderStart;i<=inorderEnd;i++){
        if(inoder[i]==num)
            return i;
    }
    return -1;
}
void postorder(NODE *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    NODE *root;
    int inorder[10],preorder[10];
    int inorderStart,inorderEnd,i;
    printf("Enter inorder length:");
    scanf("%d",&inorderEnd);
    printf("Enter the inorder traversal sequence:\n");
    for(i=0;i<inorderEnd;i++)
        scanf("%d",&inorder[i]);
    inorderStart=0;    
    printf("Enter the preorder traversal sequence:\n");
    for(i=0;i<inorderEnd;i++)
        scanf("%d",&preorder[i]);
    root = buildBinaryTree(inorder,preorder,inorderStart,inorderEnd);
    printf("Post Order Traversal of the given Binary Tree is:\n");
    postorder(root);
    return 0;
}