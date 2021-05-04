#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*Head=NULL,*last=NULL;

void create(int i){
    struct node *t;
    t=(struct node *)(malloc(sizeof(struct node)));
    t->data=i;
    t->next=Head;
    if(Head==NULL) Head=last=t;
    else{
            last->next=t;
            last=t;
        }

}
int Size(struct node *p){
    int i=0,f=0;
    while(p!=Head || f==0){
        i+=1;
        f=1;
        p=p->next;
    }
   return i;
}
void Insert(int ind,int data){
    if(ind<0 || ind>Size(Head)) return;
    struct node *t,*p;
    t=(struct node *)(malloc(sizeof(struct node)));
    p=Head;
    t->data=data;
    t->next=t;
    if(ind == 0){
        if(Head ==NULL){
            Head=t;
            Head->next=Head;
        }
        else{
            while(p->next!=Head) p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else{
        for(int j=0;j<ind-1;j++) p=p->next;
        t->next = p->next;
        p->next=t;
    }
}
int Delete(int ind){
    int x=-1;
    struct node *p,*q;
    p=Head;
    if(ind<1 || ind>Size(p)) return x;
    if(ind ==1){
        while(p->next!=Head) p=p->next;
        x=Head->data;
        if(p==Head){
            free(Head);
            Head=NULL;
        }
        else{
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else{
        for(int j=0;j<ind-2;j++) p->next;
        q=p->next;
        p->next=q->next;
        x=p->data;
        free(q);
    }

    return x;
}
void Display(struct node *p){
    int f=0;
    while(p!=Head || f==0){
        printf("%d ",p->data);
        f=1;
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
    Display(Head);
    Insert(0,12);
    Insert(4,55);
    Display(Head);
    printf("%d\n",Delete(5));
    Delete(1);
    Display(Head);
}
