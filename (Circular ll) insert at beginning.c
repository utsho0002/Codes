#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};


void print(struct Node *head){
   if (head==NULL){return;}
   struct Node *p=head;
   while(p->next != head){
    printf("%d ",p->data);
    p=p->next;
   } printf("%d",p->data);
};
//At begin.
struct Node *begin(struct Node *temp, int data){
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=temp->next;
    temp->next=new_node;
    return temp->next;
};



int main(){
    struct Node *head=NULL;
    struct Node *new;
    struct Node *temp;
    int n;
    scanf("%d",&n);
    while(n--){
        new=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL){
            head=temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }temp->next=head;
    }
    head=begin(temp,4);
    print(head);
   
}

