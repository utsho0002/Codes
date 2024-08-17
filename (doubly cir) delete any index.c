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



struct Node *d_beginning(struct Node *temp,struct Node *head){
   struct Node *p=head;
   if(head->next==head){
    head=temp=NULL;
    free(p);
    return head;
   }
   else{
   head=head->next;
   head->prev=temp;
   temp->next=head;
   free(p);
    return head;
   }
};



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



struct Node *d_pos(struct Node *temp, struct Node *head, int index) {
    int i=1;
    struct Node *p = head;
    int l=get_len(temp, head);


    if(index==1) {
        return d_beginning(temp,head);
    }else if (index==l) {
        return d_end(temp,head);
    }
    else{
        while(i!=index) {
            p=p->next;
            i++;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return head;
    }
}



int get_len(struct Node *temp, struct Node *head){  //length of the ll
    int count=1;
    while(head!=temp){
        count++;
        head=head->next;
    }
    return count;
}



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
head=d_pos(temp,head,2);
 print(temp);
}
