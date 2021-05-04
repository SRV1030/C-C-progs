#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;

void insertld(int x){
   struct Node *t;
   t=(struct Node*)(malloc(sizeof(struct Node)));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}
int count(struct Node *p){
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
void insertpos(struct Node*p,int ind,int x){
    if(ind<0 || ind>count(p)) return;
    struct Node *t;
    t=(struct Node*)(malloc(sizeof(struct Node)));
    t->data=x;
    if(ind==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<ind-1;i++) p=p->next;
        t->next=p->next;
        p->next=t;
    }


}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    int n=5,d;
    for(int i=0;i<n;i++){
      scanf("%d",&d);
      insertld(d);
    }
    display(first);
    insertpos(first,0,1000);
    display(first);
}
