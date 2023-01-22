#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void printnodes(struct node *head){
    struct node *temp=malloc(sizeof(struct node));
    temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void InsertAtKth(int k, int v){
    int ifshouldadd=1;
    struct node *newnode=malloc(sizeof(struct node));
    struct node *temp=head;
    newnode->data=v;
    newnode->next=NULL;
    if(k==0){
        newnode->next=head;
        head=newnode;
        ifshouldadd=0;
    }else{
        for(int i=0;i<k-1;i++){
            if(temp->next==NULL){
                ifshouldadd=0;
                newnode->next=NULL;
                temp->next=newnode;
                break;
            }else{
                temp=temp->next;
            }
        }
    }
    if(ifshouldadd==1){
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int findmax(){
    int max=head->data;
    struct node *temp=head;
    while(1){
        temp=temp->next;
        if(temp==NULL){
            break;
        }else{
            if(temp->data>max){
                max=temp->data;
            }
        }
    }
    return max;
}
void deletek(int k){
    struct node *temp=head;
    if(temp==NULL){
        return;
    }else if(k==0){
        head=temp->next;
        free(temp);
    }else{
        for(int i=0;i<k-1;i++){
            temp=temp->next;
        }
        struct node *temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);

    }
}
void updatek(int k, int v){
    struct node *temp=head;
    for(int i=0;i<k;i++){
        temp=temp->next;
    }
    temp->data=v;
}
int main(){
    head=NULL;
    int max;
    InsertAtKth(0,1); //1
    InsertAtKth(0,2); // 2 1
    InsertAtKth(2,-2); // 2 1 -2
    InsertAtKth(1,-1); // 2 -1 1 -2
    InsertAtKth(1,11); // 2 11 -1 1 -2
    InsertAtKth(1,3); //2 3 11 -1 1 -2
    InsertAtKth(2,10); //2 3 10 11 -1 1 -2
    InsertAtKth(2,13); // 2 3 13 10 11 -1 1 -2
    InsertAtKth(3,4); // 2 3 13 4 10 11 -1 1 -2
    InsertAtKth(4,5); // 2 3 13 4 5 10 11 -1 1 -2
    InsertAtKth(5,6); // 2 3 13 4 5 6 10 11 -1 1 -2
    deletek(8); // 2 3 13 4 5 6 10 11 1 -2
    deletek(0); //3 13 4 5 6 10 11 1 -2
    deletek(1); // 3 4 5 6 10 11 1 -2
    updatek(0,5);//5 4 5 6 10 11 1 -2
    updatek(3,-10); //5 4 5 -10 10 11 1 -2
    max=findmax();
    printf("%d\n",max);
    printnodes(head);
}