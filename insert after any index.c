// insertion of doubly ll
//after any position

#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};


//insert after Position.
struct Node *after(struct Node *head, int data, int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    int i=1;
    while(i!=index){
        p=p->next;
        i++;
    }
    ptr->prev=p;
    ptr->next=p->next;
    p->next=ptr;
    ptr->prev->next=ptr;
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
    head=after(head,22,3);
    print(head);
}

