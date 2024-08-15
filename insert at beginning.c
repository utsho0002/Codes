// insertion of doubly ll
//at beginning.

#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};


//insert at beginning.
struct Node *begin(struct Node *head, int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->prev=NULL;
    head->prev=ptr;
    ptr->next=head;
    head=ptr;
    return ptr;
};


void print(struct Node *head){
    while(head != NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}
int main(){
    struct Node *head=NULL;
    struct Node *new;
    struct Node *temp;
    int n;
    scanf("%d",&n);
    while(n--){
        new=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&new->data);
        new->prev=NULL;
        new->next=NULL;
        if(head==NULL){
            head=temp=new;
        }
        else{
            temp->next=new;
            new->prev=temp;
            temp=new;
        }
       
    }
    head=begin(head,22);
    print(head);
}

