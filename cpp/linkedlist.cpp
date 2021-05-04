#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
            int data;
            Node *next;
};

class Linkedlist{
    private:
            Node *first;
    public:
        Linkedlist(){
            first=NULL;
        }
        ~Linkedlist();

        void insertfromarray(int *a,int n);
        void display();
        void insertatend(int x);
        void Insert(int index,int x);
        int Delete(int index);
        int Length();
};
    Linkedlist::~Linkedlist(){
        Node *p=first;
        while(first){
            first=first->next;
            delete p;
            p=first;
        }
    }
    void Linkedlist::insertfromarray(int *a,int n)
        {   first=new Node;
            first->data=a[0];
            first->next=NULL;
            Node *t, *last;
            last=first;
            for(int i=1;i<n;i++){
                t= new struct Node;
                t->data=a[i];
                t->next=NULL;
                last->next=t;
                last=t;
            }
        }
        void Linkedlist :: display(){
            Node *p=first;
            while(p){
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<"\n";
        }
        void Linkedlist :: insertatend(int x){
            Node *t,*last;
            t= new Node;
            last= first;
            t->data=x;
            t->next=NULL;
            if(first==NULL) last=first=t;
            else{
                last->next=t;
                last=t;
            }
        }
        void Linkedlist::Insert(int index,int x){
            Node *t,*p=first;
            if(index <0 || index > Length()) return;
            t=new Node;
            t->data=x;
            t->next=NULL;
            if(index==0){
                t->next=first;
                first=t;
            }
            else{
                for(int i=0;i<index-1;i++)
                p=p->next;
                t->next=p->next;
                p->next=t;
            }
        }
        int Linkedlist::Delete(int index){
            Node *p,*q=NULL;
            int x=-1;
            if(index < 1 || index > Length())
            return -1;
            if(index==1)
            {
              p=first;
              first=first->next;
              x=p->data;
              delete p;
            }
            else
            {
              p=first;
              for(int i=0;i<index-1;i++)
              {
              q=p;
              p=p->next;
              }
              q->next=p->next;
              x=p->data;
              delete p;
              }
              return x;
        }
        int Linkedlist::Length(){
            Node *p=first;
            int c=0;
            while(p){
                c++;
                p=p->next;
            }
            return c;
        }

int main()
{
    int a[6]={1,2,3,4,10,20};
    Linkedlist ld;
    // ld.insertfromarray(a,6);
    // ld.Insert(2,44);
    // ld.Insert(0,44);
    ld.insertatend(32);

    // cout<<ld.Delete(2)<<" ";

    ld.display();
    return 0;
}
