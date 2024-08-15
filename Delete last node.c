// deletion of doubly ll
//last Node.

#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};


//delete last Node
struct Node *d_end(struct Node *temp){
    temp->prev->next=NULL;
    free(temp);
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
    d_end(temp);
    print(head);
}

