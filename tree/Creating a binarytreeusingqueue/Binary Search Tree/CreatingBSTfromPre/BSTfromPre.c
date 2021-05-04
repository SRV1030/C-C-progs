#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node* CreateBSTPre(struct Node *root,int pre[],int n){
    struct Stack stk;
    CreateStack(&stk,100);
    struct Node *t,*p;
    int i=0;
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while(i<n){
        if(pre[i]<p->data){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=pre[i++];
            t->rchild=t->lchild=NULL;
            p->lchild=t;
            Push(&stk,p);
            p=t;
        }
        else{
            if(pre[i]>p->data && pre[i]<( StackTop(&stk)? StackTop(&stk)->data : 32767)){
                t=(struct Node*)malloc(sizeof(struct Node));
                t->data=pre[i++];
                t->rchild=t->lchild=NULL;
                p->rchild=t;
                p=t;
            }
            else{
                p=Pop(&stk);
            }
        }
    }
    return root;
}
void Preorder(struct Node *p)
{
     if(p)
     {
     printf("%d ",p->data);
     Preorder(p->lchild);
     Preorder(p->rchild);
     }
     
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

int main()
{
    struct Node* root=NULL;
    int pre[]={30,20,10,15,25,40,50,45};
    int n=sizeof(pre)/sizeof(pre[0]);
    root=CreateBSTPre(root,pre,n);
    printf("\n");
    Inorder(root);

    

    return 0;
}

