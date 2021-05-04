#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

int Hash(int key){
    return key%10;
}
void InsertHash(struct Node* H[],int data){
    int index= Hash(data);
    SortedInsert(&H[index],data);
}

int main()
{
    struct Node *H[10],*temp;
    for(int i=0;i<10;i++) H[i]=NULL;
    InsertHash(H,11);
     InsertHash(H,12);
      InsertHash(H,1);
       InsertHash(H,23);
       temp=Search(H[Hash(1)],1);
       printf("%d",temp->data);

    return 0;
}
