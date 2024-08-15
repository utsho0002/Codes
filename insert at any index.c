// insertion of doubly ll
//at any index

#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
//code for find length of the ll
//move the p pointer untill ts become NULL
int getlen(struct Node *head){
    struct Node *p=head;
    int count=0;
    while(p != NULL){
        p=p->next;
        count++;
    }
    return count;
}

//insert at position.
struct Node *pos(struct Node *head,int data, int index){
    int l=getlen(head);
     struct Node *ptr=(struct Node *)malloc(sizeof(struct Node ));
     struct Node *p=head;
    ptr->data=data;
     if(index==1){ //code ofthe insert at beginning 
    ptr->prev=NULL;
    head->prev=ptr;
    ptr->next=head;
    head=ptr;
    return ptr;
     }
     int i=1;
     while(i != index-1){
        p=p->next;
        i++;
     }
     ptr->prev=p;
     ptr->next=p->next;
     p->next=ptr;
     ptr->next->prev=ptr;
     return head;
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
   head=pos(head,22,1);
    print(head);
}

