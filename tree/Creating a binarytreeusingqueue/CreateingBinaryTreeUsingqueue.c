#include <stdlib.h>
#include  <stdio.h>
#include "Queue.h"

struct Node* CreateTree(struct Node *root){
    int x;
    root=(struct Node*)malloc(sizeof(struct Node));
    struct Queue q;
    createQueue(&q,100);
    struct Node *p,*t;
    printf("Enter Root ");
    scanf("%d",&x);
    root->data=x;
    root->lchild=root->rchild=NULL;
    Enqueue(&q,root);
    while(!isEmpty(q)){
        p=Dequeue(&q);
        printf("Enter l.child of %d. Enter -1 for no l.child ",p->data);
        scanf("%d",&x);
        if(x!=-1){
        t=(struct Node*)malloc(sizeof(struct Node));
         t->data=x;
         t->lchild=t->rchild=NULL;
         p->lchild=t;
         Enqueue(&q,t);
        }
        printf("Enter r.child of %d. Enter -1 for no r.child ",p->data);
        scanf("%d",&x);
        if(x!=-1){
        t=(struct Node*)malloc(sizeof(struct Node));
         t->data=x;
         t->lchild=t->rchild=NULL;
         p->rchild=t;
         Enqueue(&q,t);
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
void Postorder(struct Node *p)
{
     if(p)
     {
     Postorder(p->lchild);
     Postorder(p->rchild);
     printf("%d ",p->data);
     }
      
}
void LevelOrder(struct Node *root){
    struct Queue q;
    createQueue(&q,100);
    printf("%d ",root->data);
    Enqueue(&q,root);
    while(!isEmpty(q)){
        root=Dequeue(&q);
        if(root->lchild){
            printf("%d ",root->lchild->data);
            Enqueue(&q,root->lchild);
        }
        if(root->rchild){
            printf("%d ",root->rchild->data);
            Enqueue(&q,root->rchild);
        }
    }
}
int NodeCount(struct Node *root){
    if(root) return ( NodeCount(root->lchild)+NodeCount(root->rchild))+1;
}
int Height(struct Node *root){
    int x=0,y=0;
    if(root==NULL) return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y) return x+1;
    else return y+1;
}
int main(){
    struct Node *root;
    root=CreateTree(root);
    LevelOrder(root);
    printf("\n");
    Preorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    Inorder(root);

    printf("\n");
    printf("Node count is %d\n",NodeCount(root));
    printf("Height is %d\n",Height(root));

}





















