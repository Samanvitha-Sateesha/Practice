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
int searchElementInBT(NODE *root,int num){
    int found;
    if(root==NULL)
        return 0;
    else
    {
        if(num==root->data)
            return 1;
        found=searchElementInBT(root->left,num);
        if(found != 0)
            return found;
        else
        {
            return searchElementInBT(root->right,num);
        }
    }
    return 0;
}
int main(){
    NODE *root = NULL;
    int num,res;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    printf("Enter the value to search:\n");
    scanf("%d",&num);
    res=searchElementInBT(root,num);
    (res==0)?printf("%d not found\n",num):printf("%d found\n",num);
    return 0;
}