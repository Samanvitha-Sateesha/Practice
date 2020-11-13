// C program to print out all the paths from root node to leaf nodes in a given Binary Tree.
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
void printPathsRecur(NODE *root,int paths[],int pathlen){
    if(!root)
        return;
    paths[pathlen]=root->data;
    pathlen++;
    if(root->left==NULL && root->right==NULL)
        printArray(paths,pathlen);
    else{
        printPathsRecur(root->left,paths,pathlen);
        printPathsRecur(root->right,paths,pathlen);
    }        
}
void printArray(int array[],int len){
    int i;
    printf("Path is:\n");
    for(i=0;i<len;i++)
        printf("%d ",array[i]);
    printf("\n");    
}
int main(){
    NODE *root = NULL;
    int paths[20],pathlen=0;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    printPathsRecur(root,paths,pathlen);
    return 0;
}    