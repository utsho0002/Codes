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



//at any position.
struct Node *position(struct Node *temp, int index, int data){
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    int i=1;
    struct Node *p=temp->next;
    int l= getlen(temp);
    if(index<1 || index >l+1){
        printf("invalid");
    }
    if(index==1){
       return begin(temp,data);
    }
    else{
        while(index-1 != i){
        p=p->next;
    }
    new_node->next=p->next;
    p->next=new_node;
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
    return count;
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
        new->next=NULL;
        if(head==NULL){
            head=temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }temp->next=head;
    }
   
    head=position(temp,2,45);
    print(head);
   
}

