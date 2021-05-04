#include<stdlib.h>
#include <stdio.h>
struct Node{
    struct Node* lchild;
    struct Node* rchild;
    int data;
};

struct Node* BSTInsertItr(struct Node *root,int data){
    struct Node*t=root,*r,*p;
    if(root==NULL){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->lchild=p->rchild=NULL;
        root=p;
        return root;
    }
    while(t!=NULL){
        r=t;
        if(t->data==data)return root;
        else if(data<t->data) t=t->lchild;
        else   t=t->rchild;
    }
     p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->lchild=p->rchild=NULL;
        if(data<r->data) r->lchild=p;
        else r->rchild=p;
    return root;
}
struct Node* BSTInsertrec(struct Node *root,int data){
    struct Node*p;
    if(root==NULL){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        p->lchild=p->rchild=NULL;
        return p;
    }
    if(data<root->data) root->lchild=BSTInsertrec(root->lchild,data);
    else if(data>root->data) root->rchild=BSTInsertrec(root->rchild,data);
    return root;
}
void Inorder(struct Node *p)
{
     if(p)
     {
     Inorder(p->lchild);
     printf("%d ",p->data);
     Inorder(p->rchild);
     }
      
}
int Height(struct Node *root){
    int x=0,y=0;
    if(root==NULL) return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y) return x+1;
    else return y+1;
}
struct Node * InPre(struct Node *p){
    while(p && p->rchild!=NULL) p=p->rchild;
    return p;
}
struct Node * InSuc(struct Node *p){
    while(p && p->lchild!=NULL) p=p->lchild;
    return p;
}
struct Node * BSTDelete(struct Node *p,int key){
    struct Node*q;
    if(p==NULL) return NULL;
    if(p->lchild==NULL &&p->rchild==NULL){
        free(p);
        return NULL;
    }
     if(key<p->data) p->lchild=BSTDelete(p->lchild,key);
    else if(key>p->data) p->rchild=BSTDelete(p->rchild,key);
    else{
        if(Height(p->lchild)>Height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=BSTDelete(p->lchild,q->data);
        }
        else{
            q=InSuc(p->rchild);
            p->data=q->data;
            p->rchild=BSTDelete(p->rchild,q->data);
        }
    }
    
}
struct Node* BSTSearch(struct Node *root,int data){
    struct Node*p=root;
    while(p!=NULL){
       if(p->data==data)return p;
       else if(data<p->data)p=p->lchild;
       else p=p->rchild;
    }
    return NULL;
}
int main()
{   struct Node *root=NULL,*t;
    root=BSTInsertrec(root,10);
     BSTInsertrec(root,2);
     BSTInsertrec(root,90);
      BSTInsertrec(root,210);
      BSTDelete(root,2);
      BSTInsertrec(root,1);
      Inorder(root);

    return 0;
}