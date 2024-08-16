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


//from beginning.
struct Node *d_beginning(struct Node *temp){
    struct Node *p=temp->next;
    int l=getlen(temp);
    if(l==1){
        temp=NULL;
        free(p);
    }
    else{
        temp->next=p->next;
        p->next=NULL;
        free(p);
    }
    return temp->next;
};


//From any position.
struct Node *d_pos(struct Node *temp, int index){
    struct Node *curr=temp->next;
    struct Node *nextnode;
    int i=1;
    if(index==1){
        return d_beginning;
    }
    else{
        while(i != index-1){
            curr=curr->next;
            i++;
        }
        nextnode=curr->next;
        curr->next=nextnode->next;
        free(nextnode);
        return temp->next;
    }
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
   
    temp=d_pos(temp,2);
    print(head);
   
}
