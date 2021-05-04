#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL,*last=NULL;

void create(int i){
    struct node *t,*last;
    t=(struct node *)(malloc(sizeof(struct node)));
    t->prev=NULL;
    t->data=i;
    t->next=NULL;
    if(first==NULL) first=last=t;
    else{   t->prev=last;
            last->next=t;
            last=t;
        }

}
int Size(struct node *p){
    int i=0;
    while(p!=NULL){
        i+=1;
        p=p->next;
    }
   return i;
}
void Insert(struct node *p,int ind,int data){
    if(ind<0 || ind>Size(first)) return;
    struct node *t;
    t=(struct node *)(malloc(sizeof(struct node)));
    t->data=data;
    t->next=NULL;
    t->prev=NULL;
    if(ind == 0){
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(int j=0;j<ind-1;j++) p=p->next;
        t->next = p->next;
        t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
}
int Delete(int ind){
    int x=-1;
    struct node *p;
    p=first;
    if(ind<1 || ind>Size(p)) return x;
    if(ind ==1){
        first=first->next;
        if(first) first->prev=NULL;
        x=p->data;
        free(p);
        return x;
    }
    else{
        for(int j=0;j<ind-1;j++) p=p->next;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        x=p->data;
        free(p);
        return x;
    }
}
void Display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
// {   int val,s=0;
//     printf("Enter your data and -1 to stop");
//     while(val!=-1){
//       scanf("%d",&val);
//       create(val);
//       s+=1;
//     }
     for(int i=0;i<8;i++) create(i);
    // Delete(s);
    Display(first);
    Insert(first,0,12);
    Insert(first,2,55);
    Display(first);
    printf("%d\n",Delete(5));
    Delete(1);
    Display(first);
}
