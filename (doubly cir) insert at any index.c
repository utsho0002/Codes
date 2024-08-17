#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};


void print(struct Node *temp){
   struct Node *p=temp->next;
   while(p != temp){
    printf("%d ",p->data);
    p=p->next;
   }  printf("%d ",p->data);
};


struct Node *beg(struct Node *head,int data){
    struct Node *new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev=new;
    return new;
};



struct Node *at_pos(struct Node *head, int index, int data){
    struct Node *new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    struct Node *p=head;
    int i=1;
    while(index-1 != i){
        p=p->next;
        i++;
    }
    new->prev=p;
    new->next=p->next;
    p->next->prev=new;
    p->next=new;
    return head;
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
            head->prev=head;
            head->next=head;
        }
        else{
            temp->next=new;
            new->prev=temp;
            new->next=head;
            head->prev=new;
            temp=new;
        }
    }
    head=at_pos(head,2,88);
    print(temp);
}
