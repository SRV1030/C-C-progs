#include <stdlib.h>
#include <stdio.h>

int size=0;
struct node{
    int data;
    struct node* next;
};

void push(struct node **head,int data){
    size++;
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
    if(*head==NULL){
        *head=t;
        return;
    }
     struct node *last=*head;
    while(last->next!=NULL) last=last->next;
    last->next=t;
    return;
}
void FandBsplit(struct node *head, struct node **f,struct node **b){
    struct node*slow,*fast;
    slow=head;
    fast=head->next;
    while(fast){
        fast=fast->next;
        if(fast){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *f=head;
    *b=slow->next;
    slow->next=NULL;
    
}
struct node *merge(struct node *l,struct node *r){
    struct node *res=NULL;
    if(l==NULL) return r;
    else if(r==NULL) return l;
    if(l->data<=r->data){
        res=l;
        res->next= merge(l->next,r);
    }
    else{
        res=r;
        res->next= merge(l,r->next);
    }
    return res;
}
void MergeSort(struct node **head){
    struct node *h=*head;
    struct node *l,*r;
    if(h==NULL || h->next==NULL) return;
    FandBsplit(h,&l,&r);
    MergeSort(&l);
    MergeSort(&r);
    *head=merge(l,r);
}
void printList(struct node* n) 
{ 
    while (n) { 
        printf("%d ", n->data); 
        n = n->next; 
    } 
} 
void revPrint(struct node *n){
    int a[size+1],i=0;
    while (n) { 
       a[i++]=n->data; 
        n = n->next;
    } 
    while(i--){
       printf("%d ", a[i]);  
    }
}
int main()
{
    int ch,d;
    struct node* a = NULL;
    printf("Enter your choice: ");
    scanf("%d",&ch);
    while(ch!=5){
        switch(ch){
            case 1: scanf("%d",&d);
                    push(&a, d);
                    break;
            case 2: if(a){
                        printList(a);
                        printf("\n");  
                       
                    }else{
                        printf("List is Empty \n");   
                    }
                    break;
            case 3: if(a){
                        revPrint(a);
                        printf("\n");  
                    }else{
                        printf("List is Empty \n");   
                    }
                    break;
            case 4: if(a){
                        MergeSort(&a); 
                        printList(a);
                        printf("\n");   
                    }else{
                        printf("List is Empty \n");   
                    }
                    break; 
            default: break;
            
        }
        printf("Enter your choice: ");
        scanf("%d",&ch);
    }
}