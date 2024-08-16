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



//From the end;
struct Node *d_end(struct Node *temp){
    struct Node *curr= temp->next;
    struct Node *prev;
    int l=getlen(temp);
    if(l==1){
        temp=NULL;
        free(curr);
    }
    else{
    while(curr->next != temp->next){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    temp=prev;
    free(curr);
    return temp->next;}
};


//find length.
int getlen(struct Node *temp){
    struct Node *p=temp->next;
    int count=0;
    while(p != temp){
        count++;
        p=p->next;
    }
    count++;
    return count;}


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
    
    head=d_end(temp);
    print(head);
   
}
