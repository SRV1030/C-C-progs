#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
 *a=*a^*b;
 *b=*a^*b;
 *a=*a^*b;
}
void heapify(int a[],int n,int i){
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && a[l] > a[largest]) 
        largest = l; 
    if (r < n && a[r] > a[largest]) 
        largest = r; 
    if (largest != i){ 
        swap(&a[i], &a[largest]); 
        heapify(a, n, largest); 
    }
}
void heapsort(int a[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}
int main()
{   
    int*a,n;
    printf("Enter the array size \n");
    scanf("%d",&n); 
    a=(int *)malloc(sizeof(int)*n);
    printf("Enter the array: \n");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    heapsort(a,n);
    printf("Sorted array: \n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
