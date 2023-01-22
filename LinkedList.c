#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void addatend(struct node *head, int i){
    struct node *temp=malloc(sizeof(struct node));
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=i;
    newnode->next=NULL;
    temp=head;
    while(1){
        if(temp->next==NULL){
            temp->next=newnode;
            break;
        }
        else{
            temp=temp->next;
        }
    }
}
void countnodes(struct node *head){
    struct node *temp=malloc(sizeof(struct node));
    int count=0;
    temp=head;
    while(temp){
        count+=1;
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n%d\n",count);
}
struct node *addatbeg(struct node *head){
    int value=0;
    //printf("Enter number:");
    //scanf("%d",&value);
    struct node *current=malloc(sizeof(struct node));
    current->data=value;
    current->next=head;
    return current;
}
void deleteatend(struct node *head){
    struct node *slast=malloc(sizeof(struct node));
    slast=head;
    while(1){
        if(slast->next->next==NULL){
            free(slast->next);
            slast->next=NULL;
            break;
        }else{
            slast=slast->next;
        }
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    addatend(head,2);
    addatend(head,3);
    addatend(head,4);
    addatend(head,-1);
    countnodes(head);
    
}