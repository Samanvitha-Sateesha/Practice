// Inorder linked lists -- To insert nodes into a linked list in increasing order
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}NODE;
NODE* inserttosortedll(NODE *head,int num){
    struct node *temp,*new;
    int flag = 0;
    NODE* curr = head;
    new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    new->link = NULL;
    if(!head){
        return new;
    }
    while(curr != NULL && curr->data < new->data){
        temp = curr;
        curr = curr->link;
        flag =1;
    }
    if(flag){
        new->link = curr;
        temp->link = new;
    }
    else{
        new->link = curr;
        head = new;
    }
    return head;
}
void display(struct node *head){
    struct node *temp = head;
    printf("List is:\n");
    while (temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("END\n");
}
NODE *reversePairIter(NODE *head){
    NODE *temp1=NULL,*temp2=NULL,*curr=head;
    while (curr != NULL && curr->link != NULL)
    {
        if(temp1!=NULL){
            temp1->link->link=curr->link;
        }
        temp1=curr->link;
        curr->link=curr->link->link;
        temp1->link=curr;
        if(temp2==NULL)
            temp2=temp1;
        curr = curr->link;
    }
    return temp2; 
}
int main(){
    NODE *head = NULL;
    int num,choice;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Add to the list\n2.Display\n3.Reverse Pair \nAny number to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the value of data to be inserted: ");
                scanf("%d",&num);
                head = inserttosortedll(head,num);
                printf("INSERTED\n");
            break;
        case 2: display(head);
            break;
        case 3: head=reversePairIter(head);
                printf("Reversed!\n");
                display(head);
                break;    
        default: exit(0);
        }
    }
    return 0;
}