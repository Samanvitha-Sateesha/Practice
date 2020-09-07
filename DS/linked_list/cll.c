#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}NODE;
// struct header{
//     int data;
//     struct header *ptr;
//     struct header *last;
// }*head;
NODE *head, *rear = NULL;
void initilise(){
    head = (NODE *)malloc(sizeof(NODE));
    head->data = 0;
    head->ptr = NULL;
    // head->last = rear;
}
NODE* insertbeg(int num){
    NODE* new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    if (head->ptr == NULL){    
        new->ptr = new;
        head->ptr = new;
        rear = new;
        head->data++;
        return new;
    }
    new->ptr = head->ptr;
    head->ptr = new;
    rear->ptr=new;
    head->data++;
    return new;
}
NODE* insertend(int num){
    NODE* new = (NODE *)malloc(sizeof(NODE));
    new->data = num;
    if (head->ptr == NULL){    
        new->ptr = new;
        head->ptr = new;
        rear = new;
        head->data++;
        return new;
    }
    rear->ptr = new;
    new->ptr = head->ptr;
    rear = new;     
    head->data++;
    return new;
}

void display(){
    NODE* temp = head->ptr;
    if(head->ptr == NULL){
        printf("Empty list\n");
        return;
    }
    printf("Contents of the list are:\n");
    for(int i=0;i<head->data;i++){
        printf("%d\n",temp->data);
        temp = temp->ptr;    
    }
    printf("End of List\n");
}
void delete(int num){
    NODE *temp = head->ptr;
    if(head->ptr == NULL){
        printf("Empty list\n");
        return;
    }
    NODE *prev = head->ptr;
    if(temp->data == num){
        temp = temp->ptr;
        head->ptr = temp;
        rear = temp;
        head->data--;
        printf("Deleted\n");
        return;
    }
    while (temp->ptr != head->ptr)
    { 
        temp = temp->ptr;
        if(temp->data == num){
            prev->ptr = temp->ptr;
            // temp = temp->ptr;
            head->data--;
            printf("Deleted\n");
            break;
        }
        if (prev->ptr != head->ptr)
        {
            prev = prev->ptr; 
        }           
    }
    if(prev->ptr == head->ptr){
        rear = prev;
    }
}
int search(int num){
    int i;
    NODE* temp = head->ptr;
    if(head->ptr == NULL){
        printf("Empty list\n");
        return 0;
    }
    for(i=0;i<head->data;i++){
        if(temp->data == num)
            return 1;
        temp = temp->ptr;    
    }
    return 0;
}
int main(){
    initilise();
    printf("Linked list initialised\n");
    int ch,num,res;
    while (1)
    {
        printf("Choose the operation you want to perform\n");
        printf("1.Insert at beginning\n2.Insert at end\n3.Display\n");
        printf("4.Delete a node with certain value\n5.Search an item\n");
        printf("Any other option to exit\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:printf("Enter the vale of element to be inserted:");
               scanf("%d",&num);
               insertbeg(num);  
            break;
        case 2:printf("Enter the vale of element to be inserted:");
               scanf("%d",&num);
               insertend(num);  
            break;
        case 3: display();
            break;
        case 4:printf("Enter the vale of element to be deleted:");
               scanf("%d",&num);
               delete(num);
            break;
        case 5:printf("Enter the vale of element to be searched:");
               scanf("%d",&num);
               res =  search(num);
               (res==1) ? printf("Search Successful\n"):printf("Search Unsuccessful\n");
               break;                  
        default: exit(0);
        }
    }    
}