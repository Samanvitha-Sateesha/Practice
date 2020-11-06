// C program to print the contents of the tree by traversing the tree in three ways, namely inorder,preorder and postorder.
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
void inorder(NODE *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(NODE *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder(NODE *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    NODE *root = NULL;
    int choice;
    root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
    insertright(root->left,5);
    insertleft(root->right,6);
    insertright(root->right,7);
    while(1){
        printf("Choose your traversal type\n1.Inorder\n2.Post-order\n3.Pre-order\nExit\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Tree contents are:\n");
                inorder(root);
            break;
        case 2: printf("Tree contents are:\n");
                postorder(root);
            break;
        case 3: printf("Tree contents are:\n");
                preorder(root);
            break;
        default: exit(0);
        }
    }
    return 0;
}