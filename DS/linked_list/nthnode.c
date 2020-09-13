// The most efficient method to find the nth node from the end of a linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}NODE;
void createlist(NODE **head,int num){
    struct node *temp,*new;
    new = (NODE *)malloc(sizeof(NODE));
    temp = *head;
    if(temp == NULL){
        // temp = malloc(sizeof(NODE));
        new->data = num;
        new->link = NULL;
        *head = new;
        return;
    }
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    new->data = num;
    temp->link = new;
    new ->link = NULL;
    // return head;
}
void display(struct node *head){
    struct node *temp = head;
    // if(temp->link == NULL){
    //     printf("Empty List\n");
    //     return;
    // }
    printf("List is:\n");
    while (temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("END\n");
    
}
struct node* nthnodefromend(NODE *head, int endnth){
    NODE* ntemp = head;
    NODE* npthnode = NULL;
    
    int count;
    for(count=1;count<endnth;count++){
        if(ntemp)
            ntemp = ntemp->link;
    }
    while (ntemp)
    {
        if(npthnode == NULL)
            npthnode = head;
        else
        {
            npthnode = npthnode->link;
        }
        ntemp = ntemp->link;    
    }
    if(npthnode)
        return npthnode;
    return NULL;    
}
int main(){
    // NODE* head = (NODE *)malloc(sizeof(NODE));
    NODE *head = NULL;
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    int nthend;
    createlist(&head,10);
    createlist(&head,20);
    createlist(&head,30);
    createlist(&head,40);
    createlist(&head,50);
    display(head);
    printf("Enter the value of n to find the value in nth node from end: ");
    scanf("%d",&nthend);
    temp = nthnodefromend(head,nthend);
    printf("The data item in the nth node from end is:%d\n",temp->data);
    return 0;
}