struct Node{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H,int data){
    struct Node *q=NULL,*t,*p=*H;
    t=(struct Node *)malloc(sizeof(struct Node *));
    t->data=data;
    t->next=NULL;
    if(*H==NULL) *H=t;
    else{
        while(p && p->data<data){
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next=*H;
            *H=t;
        }else{
            t->next=q->next;
            q->next=t;
        }
    }
    
}
struct Node* Search(struct Node *p,int data){
    while(p!=NULL){
        if(data==p->data) return p;
        p=p->next;
    }
    return NULL;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
