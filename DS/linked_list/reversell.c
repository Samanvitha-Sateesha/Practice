// To reverse a singly linked list which is sorted in ascending order

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
NODE* reverselist(NODE* head){
    NODE *temp=NULL, *nextnode = NULL;
    while (head)
    {
        nextnode = head->link;
        head->link = temp;
        temp = head;
        head = nextnode;
    }
    return temp;
    
}
int main(){
    NODE *head = NULL;
    int num,choice;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Add to the list\n2.Display\n3.To reverse the list\nAny number to exit\n");
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
        case 3: head = reverselist(head);
            printf("List reversed\n");
            break;    
        default: exit(0);
        }
    }
    return 0;
}