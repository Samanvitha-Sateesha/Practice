#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}NODE;
NODE* inserttosortedll1(NODE *head1,int num){
    struct node *temp,*new;
    int flag = 0;
    NODE* curr = head1;
    new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    new->link = NULL;
    if(!head1){
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
        head1 = new;
    }
    return head1;
}
NODE* inserttosortedll2(NODE *head2,int num){
    struct node *temp,*new;
    int flag = 0;
    NODE* curr = head2;
    new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    new->link = NULL;
    if(!head2){
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
        head2 = new;
    }
    return head2;
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
NODE* mergeSortedLl(NODE* a, NODE* b){
    NODE* result = NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data <= b->data){
        result = a;
        result->link = mergeSortedLl(a->link,b);
    }        
    else
    {
        result=b;
        result->link = mergeSortedLl(a,b->link);
    }
    return result;
}
int main(){
    NODE *head1 = NULL, *head2=NULL,*head=NULL;
    int num,choice;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Add to the list-1\n2.Add to the list-2\n3.Display\n4.Merge two lists\nAny number to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the value of data to be inserted: ");
                scanf("%d",&num);
                head1 = inserttosortedll1(head1,num);
                printf("INSERTED\n");
            break;
        case 2: printf("Enter the value of data to be inserted: ");
                scanf("%d",&num);
                head2 = inserttosortedll2(head2,num);
                printf("INSERTED\n");
            break;
        case 3: printf("Contents of first list are:\n");
                display(head1);
                printf("Contents of second list are:\n");
                display(head2);
            break;
        case 4: head = mergeSortedLl(head1,head2);
                display(head);
                break;    
        default: exit(0);
        }
    }
    return 0;
}