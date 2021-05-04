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
void deleteNode(struct node** head, int key)
{
    if (*head == NULL)
        return;
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
    struct node *last=*head,*d;
    if((*head)->data==key)
    {
        while(last->next!=*head)
            last=last->next;
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
    }
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
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
    for(int i=0;i<8;i++) create(i);
    printf("The linked list is:\n");
    Display(Head);
    printf("Enter 1 to at the index of node.\nEnter 2 to Delete at index node.\nEnter any other value to exit\n\n");
    int z=0,s,i,j,k;
    scanf("%d",&s);
    while(s>0 && s<3){
        switch(s){
            case 1: printf("Inserting at index of node:\n");
                    printf("Enter the index and the value\n");
                    scanf("%d%d",&j,&k);
                    Insert(j,k);
                    Display(Head);
                    break;
            case 2: printf("Deleteing the value:\n");
                    printf("Enter the value:\n");
                    scanf("%d",&i);
                    deleteNode(&Head,i);
                    Display(Head);

                    break;
        }
        printf("Enter your new choice: ");
        scanf("%d",&s);
        printf("\n");
    }

}
