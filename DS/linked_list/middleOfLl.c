// Program to find the middle element of a singly linked list
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
NODE *findMiddle(NODE *head){
    NODE *ptr1=head, *ptr2=head;
    int i=0;
    while(ptr1->link != NULL){
        if(i==0){
            ptr1 = ptr1->link;
            i=1;
        }
        else if(i==1){
            ptr1=ptr1->link;
            ptr2=ptr2->link;
            i=0;
        }
    }
    return ptr2;
}
int main(){
    NODE *head = NULL,*temp;
    int num,choice;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Add to the list\n2.Display\n3.Find the node in the middle\nAny number to exit\n");
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
        case 3: temp = findMiddle(head);
        printf("The address of middle node is %u and data is %d\n",temp,temp->data);
        break;    
        default: exit(0);
        }
    }
    return 0;
}