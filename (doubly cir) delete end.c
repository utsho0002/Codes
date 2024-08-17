#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
struct Node *next;
struct Node *prev;
 };


void print(struct Node *temp){
  struct Node *p=temp->next;
  while(p !=temp){
    printf("%d ",p->data);
    p=p->next;
  }printf("%d",p->data);
}




struct Node *d_end(struct Node *temp, struct Node *head){
    struct Node *p=temp;
    if(head->next==head){
        head=temp=NULL;
        free(p);
        return head;
    }
    else{
        temp=temp->prev;
        temp->next=head;
        head->prev=temp;
        free(p);
        return temp;
    }
};





int  main(){
struct Node *head=NULL;
struct Node *new;
struct Node *temp;
int n;
scanf("%d",&n);
while (n--){
new=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
if(head==NULL)
{head=temp=new;
head->prev=head;
head->next=head;}
else
{
temp->next=new;
new->prev=temp;
new->next=head;
head->prev=new;
temp=new;}
}

temp=d_end(temp,head);

 print(temp);
}
