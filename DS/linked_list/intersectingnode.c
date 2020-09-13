// Suppose there are two singly linked lists which merge to become one list.
// This program is an efficient one to find the node at which two lists merge to become one.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
NODE* inserttosortedll3(NODE *head3,NODE *head1,NODE *head2,int num){
    struct node *temp,*new,*rear1=head1,*rear2=head2;
    int flag = 0;
    NODE* curr = head3;
    new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    new->link = NULL;
    while(rear1->link!= NULL){
        rear1=rear1->link;
    }
    while (rear2->link != NULL)
    {
        rear2 = rear2->link;
    }
    
    if(!head3){
        rear1->link = new;
        rear2->link = new;
        head3 = new;
        return head3;
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
    return head3;
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
int intersectingnode(NODE* head1,NODE* head2){
    int l1=0, l2=0,d=0;
    NODE *temp1=head1,*temp2=head2;
    while(temp1 != NULL){
        l1++;
        temp1 = temp1->link;
    }
    while (temp2 != NULL)
    {
        l2++;
        temp2 = temp2->link;
    }
    d = abs(l1-l2);
    if(l1<l2){
        temp1=head2;
        temp2=head1;
    }
    else{
        temp1=head1;
        temp2=head2;
    }
    for(int i=0;i<d;i++){
        temp1=temp1->link;
    }
    while (temp1!=NULL && temp2 !=NULL)
    {
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->link;
        temp2=temp2->link;
    }
    return 0;
}
int main(){
    NODE *head1 = NULL, *head2=NULL,*head3=NULL;
    int num,choice,res;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Add to the list-1\n2.Add to the list-2\n3.Insert to third ll\n4.Display\n5.Intersecting Node\nAny number to exit\n");
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
        case 3: printf("Enter the value of data to be inserted: ");
                scanf("%d",&num);
                head3 = inserttosortedll3(head3,head1,head2,num);
                printf("INSERTED\n");
            break;
        case 4: printf("Contents of first list are:\n");
                display(head1);
                printf("Contents of second list are:\n");
                display(head2);
            break;
        case 5: res = intersectingnode(head1,head2);
            if(res){
                printf("The node intersects at value: %d\n",res);
            }    
            else{
                printf("Does not intersect\n");
            }
            break;    
        default: exit(0);
        }
    }
    return 0;
}