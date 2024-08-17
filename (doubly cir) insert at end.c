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



struct Node *end(struct Node *head,struct Node *temp,int data){
    struct Node *new=(struct Node *)malloc(sizeof(struct Node ));
    new->data=data;
    new->prev=temp;
    new->next=head;
    temp->next=new;
    temp=new;
    return temp;
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
   
    temp=end(head,temp,3);
    
    print(temp);
}
