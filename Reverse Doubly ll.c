//Reverse doubly ll
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node *reverse(struct Node *head, struct Node *temp){
    struct Node *current=head;
    struct Node *next_node;
    while(current!=NULL){
        next_node=current->next;
        current->next=current->prev;
        current->prev=next_node;
        current=next_node;
    }
    current=head;
    head=temp;
    temp=current;
    return head;
}


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
    head=reverse(head,temp);
    print(head);
}
