#include<stdio.h>
#include<stdlib.h>
// #include<string.h>
int k,top=-1,*arr;
void put(int num){
    int small = arr[0];
    int j;
    for(int i=0;i<top;i++){
        if(arr[i]<small){
            small=arr[i];
            j=i;
        }
        if(arr[i]==num)
            return;
    }
    if(top!=k){
        top++;
        arr[top]=num;
        printf("%d",num);
    }    
    else{
        arr[j]=num;
    }
    // return arr;
}

int main(){
    int c,num;
    char op[15];
    printf("Enter the maximum capacity:");
    scanf("%d",&k);
    int arr[k];
    printf("Enter the count:");
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        int ch;
        // fflush(stdin);
        printf("Enter operation: \n");
        // fflush(stdin);
        // fgets(op,sizeof(op),stdin);
        while ((ch = getchar()) != '\n');
        fgets(op,sizeof(op),stdin);
        if(op[4]>= '0' && op[4] <= '9'){
            printf("True");
        }
        else
        {
            printf("False");
        }
        
        
        // if(op[4] != 'V'){
        //     num = op[4] - '0';
            // printf("%d",num);
            // fflush(stdin);
        //     put(num);
        // }
        
        // else{
        //     printf("Will update!!!!!!!!!!");
        // }
        // fflush(stdin);
    }
    return 0;
}