// Inorder linked lists -- To insert nodes into a linked list in increasing order
// After a linked list is formed we are going to reverse the value in pairs.
// 1->2->3->4->5 will become 2->1->4->3->5
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
NODE* reversePairRecursive(NODE* head){
    NODE *temp;
    if(head == NULL || head->link == NULL)
        return head;
    else {
        temp=head->link;
        head->link=temp->link;
        temp->link = head;
        head = temp;
        head->link->link=reversePairRecursive(head->link->link);
        
    }    
    return head;
}
int main(){
    NODE *head = NULL;
    int num,choice;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Add to the list\n2.Display\n3.Reverse in Pairs\nAny number to exit\n");
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
        case 3: head = reversePairRecursive(head);
                display(head);
                break;          
        default: exit(0);
        }
    }
    return 0;
}