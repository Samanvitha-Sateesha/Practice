// C program to check if the sum-of-nodes-in root-to-leaf path is equal to a given sum.
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
int hasPathSum(NODE *root,int paths[],int pathlen,int remSum){
    if(!root)
        return;
    paths[pathlen]=root->data;
    pathlen++;
    remSum-=root->data;
    if(root->left==NULL && root->right==NULL){
        if(remSum==0)
            return 1;
        return 0;    
    }
        
    else{
        if(root->left && root->right){
            return (hasPathSum(root->left,paths,pathlen,remSum)|| hasPathSum(root->right,paths,pathlen,remSum));
        }
        if(root->left)
            return hasPathSum(root->left,paths,pathlen,remSum);
        if(root->right)
            return hasPathSum(root->right,paths,pathlen,remSum);    
    }        
}
int main(){
    NODE *root = NULL;
    int paths[20],pathlen=0,sum;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    printf("Enter the sum for which u want to check if a path exists:\n");
    scanf("%d",&sum);
    (hasPathSum(root,paths,pathlen,sum)==1)?printf("Path with the gievn sum exists\n"):printf("Path with the given sum doesnt exists\n");
    return 0;
}    