#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hash(int key){
    return key%SIZE;
}
int LinearProbe(int H[],int key){
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0) i++;
    return (index+i)%SIZE;
}
void Insert(int H[],int key){
    int index=hash(key);
    if(H[index]!=0) index= LinearProbe(H,key);
    H[index]=key;
}
int SearchLP(int H[],int key){
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key){
        i++;
        if(H[(index+i)%SIZE]==0){
            return -1;
        }
    }
    return (index+i)%SIZE;
}
int main()
{
    int H[SIZE]={0};
    Insert(H,10);
     Insert(H,20);
     Insert(H,43);
     printf("%d ",SearchLP(H,20));
     printf("%d ",SearchLP(H,21));
     
    
    

    return 0;
}
