#include<stdio.h>

int binarysearch(int a[],int l,int r,int k){
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==k) return m;
        else if(a[m]>k) r=m-1;
        else l=m+1;
    }
    return -1;
}
int main(){
    int A[]={1,2,3,22,33,44,11,2,3,4};
    int n= sizeof(A)/sizeof(0);
    printf("%d %d",binarysearch(A,0,n-1,33),A[binarysearch(A,0,n-1,33)]);
}
