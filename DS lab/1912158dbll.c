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
void deleteNode(struct node** head_ref, struct node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}
void deleteNodeval(struct node** head_ref, int n)
{   int f=0;
    if (*head_ref == NULL)
        return;

    struct node* current = *head_ref;
    int i;
    for (int i = 0; current != NULL && i < Size(first); i++){
        current = current->next;
        if(current->data==n){
            f=1;
            break;
        }
    }
    if (current == NULL)
        return;
    if(f==0) return;
    deleteNode(head_ref, current);
}


void Display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    for(int i=0;i<8;i++) create(i);
    printf("The linked list is:\n");
    Display(first);
    printf("Enter 1 to Insert before first node.\nEnter 2 to Insert before the index node.\nEnter 3 to Insert after index node.\nEnter 4 to Insert at last node.\nEnter 5 to Delete at index node.\nEnter any other value to exit\n\n");
    int s,j,k,i;
    scanf("%d",&s);
    while(s>0 && s<6){
        switch(s){
            case 1: printf("Inserting before the first node:\n");
                    printf("Enter the value:\n");
                    scanf("%d",&i);
                    Insert(first,0,i);
                    Display(first);
                    break;
            case 2: printf("Inserting before the index node:\n");
                    printf("Enter the index and the value\n");
                    scanf("%d%d",&j,&k);
                    Insert(first,j-1,k);
                    Display(first);
                    break;
            case 3: printf("Inserting after the index node:\n");
                    printf("Enter the index and the value\n");
                    scanf("%d%d",&j,&k);
                    Insert(first,j,k);
                    Display(first);
                    break;
            case 4:printf("Inserting before the last node:\n");
                    printf("Enter the value:\n");
                    scanf("%d",&i);
                    Insert(first,Size(first),i);
                    Display(first);
                    break;
            case 5: printf("Deleteing the value:\n");
                    printf("Enter the value:\n");
                    scanf("%d",&i);
                    deleteNodeval(&first,i);
                    Display(first);
                    break;
            default : printf("Exit:\n");
                     break;
        }
        printf("Enter your new choice: ");
        scanf("%d",&s);
        printf("\n");
    }

}
