#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void push(struct Node** head_ref,int data){
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=(*head_ref);
    *head_ref=temp;

}
void printList(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void ReverseIt(struct Node **head_ref){
    if(*head_ref==NULL|| (*head_ref)->next==NULL) return;
    struct Node *prv=NULL,*cur=*head_ref,*nxt=NULL;
    while(cur !=NULL){
        nxt=cur->next;
        cur->next=prv;
        prv=cur;
        cur=nxt;
    }
    *head_ref=prv;
}
void ReverseRecur(struct Node **head_ref){
    if(*head_ref==NULL|| (*head_ref)->next==NULL) return;
    struct Node *cur=*head_ref;
    struct Node *nxt=cur->next;
    *head_ref=(*head_ref)->next;
    ReverseRecur(head_ref);
    nxt->next=cur;
    cur->next=NULL;

}
struct Node* ReverseGrp(struct Node **head_ref,int k){
    if(*head_ref==NULL||(*head_ref)->next==NULL) return *head_ref;
    struct Node *prev=NULL,*curr=(*head_ref),*nxt=NULL;
    int count=0;
    while(count<k && curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        count++;
    }
    if(nxt!=NULL) (*head_ref)->next=ReverseGrp(&nxt,k);

    return prev;
}
int main()
{
   struct Node *head=NULL;
   push(&head,23);
   push(&head,44);
   push(&head,54);
   push(&head,64);
   ReverseRecur(&head);   
   head=ReverseGrp(&head,4);
   printList(head);

}
