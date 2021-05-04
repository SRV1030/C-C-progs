#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;

void create(int i){
    struct node *t,*last;
    t=(struct node *)(malloc(sizeof(struct node)));
    t->data=i;
    t->next=NULL;
    if(first==NULL) first=last=t;
    else{
            last->next=t;
            last=t;
        }

}
void createld(int a[],int n){
    struct node *t,*lst;
    first=(struct node*) (malloc(sizeof(struct node)));
    first->data=a[0];
    first->next=NULL;
    lst=first;
    for(int i=1;i<n;i++){
        t= (struct node*) (malloc(sizeof(struct node)));
        t->data=a[i];
        t->next=NULL;
        lst->next=t;
        lst=t;
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
    if(ind == 0){
        t->next=first;
        first=t;
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
    p=first;
    if(ind<1 || ind>Size(p)) return x;
    if(ind ==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int j=0;j<ind-1;j++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
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
int findmid(){
    int x=-1;
    struct node *p;
    p=first;
    if(p==NULL) return x;
    else{
        int s= Size(p);
        int m= (s%2)? (s+1)/2:s/2;
        for(int i=0;i<m-1;i++)p=p->next;
        x=p->data;
        return x;
    }
}
int Deletemid(){
    int ind,x=-1;
    struct node *p,*q;
    p=first;
    if(p==NULL) return x;
    int s=Size(p);
    ind= (s%2)? (s+1)/2:s/2;
    if(ind ==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int j=0;j<ind-1;j++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
int findind(int ind){
    int x=-1;
    if(ind<1 || ind>Size(first)) return x;
    struct node *p;
    p=first;
    if(p==NULL) return x;
    else{
        for(int i=0;i<ind-1;i++)p=p->next;
        x=p->data;
        return x;
    }
}

int main(){
// {   int val,s=0;
//     printf("Enter your data and -1 to stop");
//     while(val!=-1){
//       scanf("%d",&val);
//       create(val);
//       s+=1;
//     }
     // for(int i=0;i<8;i++) create(i);
    // Delete(s);
    int A[]={1,2,3,4,5,6,7,8,12,23};
    int n= sizeof(A)/sizeof(0);
    createld(A,n);
    Display(first);
    printf("%d \n",Deletemid());
    printf("%d \n",findmid());
    printf("%d \n",Delete(4));
    Insert(first,4,156);
    printf("%d \n",findind(4));
    Display(first);
}
