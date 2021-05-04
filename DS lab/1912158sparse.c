#include<stdlib.h>
#include <stdio.h>
struct sparse{
    int size;
    int mat[1000][4];
};
struct sparse s[6];
void printspar(int ss){
    printf("\nRow Coloumn Value\n");
    for (int i=0; i<s[ss].size; i++) 
    { 
        for (int j=0; j<3; j++) 
            printf("%d ", s[ss].mat[i][j]); 
  
        printf("\n"); 
    } 

}
void addspar(){
    int i=0,j=0;
    while(i<s[0].size&&j<s[1].size)
            { 
                if(s[0].mat[i][0]<s[1].mat[j][0]){
                    s[2].mat[s[2].size][0]=s[0].mat[i][0];
                    s[2].mat[s[2].size][1]=s[0].mat[i][1];
                    s[2].mat[s[2].size][2]=s[0].mat[i][2];
                    s[2].size++;
                    i++;
                   
                }
                else if(s[0].mat[i][0]>s[1].mat[j][0]){
                    s[2].mat[s[2].size][0]=s[1].mat[j][0];
                    s[2].mat[s[2].size][1]=s[1].mat[j][1];
                    s[2].mat[s[2].size][2]=s[1].mat[j][2];
                    s[2].size++;
                    j++;
                    
                }
                else if(s[0].mat[i][1]<s[1].mat[j][1]){
                    s[2].mat[s[2].size][0]=s[0].mat[i][0];
                    s[2].mat[s[2].size][1]=s[0].mat[i][1];
                    s[2].mat[s[2].size][2]=s[0].mat[i][2];
                    s[2].size++;
                    i++;
                    
                }
                 else if(s[0].mat[i][1]>s[1].mat[j][1]){
                    s[2].mat[s[2].size][0]=s[1].mat[j][0];
                    s[2].mat[s[2].size][1]=s[1].mat[j][1];
                    s[2].mat[s[2].size][2]=s[1].mat[j][2];
                    s[2].size++;
                    j++;
                   
                }
                else{
                    s[2].mat[s[2].size][0]=s[1].mat[j][0];
                    s[2].mat[s[2].size][1]=s[1].mat[j][1];
                    s[2].mat[s[2].size][2]=s[1].mat[j][2]+s[0].mat[i][2];
                    s[2].size++;
                    j++;
                    i++;
                   
                }
            }
    while(i<s[0].size){
                s[2].mat[s[2].size][0]=s[0].mat[i][0];
                s[2].mat[s[2].size][1]=s[0].mat[i][1];
                s[2].mat[s[2].size][2]=s[0].mat[i][2];
                s[2].size++;
                i++;
            }
     while(j<s[1].size){
                    s[2].mat[s[2].size][0]=s[1].mat[j][0];
                    s[2].mat[s[2].size][1]=s[1].mat[j][1];
                    s[2].mat[s[2].size][2]=s[1].mat[j][2];
                    s[2].size++;
                    j++;
            }
                
           
        printspar(2);
    
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
void transpspar(int ss){
    for(int i=0;i<s[ss].size;i++)
    {
         s[ss+3].mat[s[ss+3].size][0]=s[ss].mat[i][1];
         s[ss+3].mat[s[ss+3].size][1]=s[ss].mat[i][0];
         s[ss+3].mat[s[ss+3].size][2]=s[ss].mat[i][2];
         s[ss+3].size++;
    }
    for(int i=0;i<s[ss+3].size-1;i++)
    {
        int ind=i;
        for(int j=i+1;j<s[ss+3].size;j++){
            if(s[ss+3].mat[i][0]>s[ss+3].mat[j][0]) ind=j; 
        }
        
        swap(&s[ss+3].mat[i][0],&s[ss+3].mat[ind][0]);
        swap(&s[ss+3].mat[i][1],&s[ss+3].mat[ind][1]);
        swap(&s[ss+3].mat[i][2],&s[ss+3].mat[ind][2]);
    }
    printspar(ss+3);
 }
 
void multiply(){
  int kpos, lpos, r, c, tempk, templ, sum;
   
    printf("\nTranspose of matrix 2 is\n");
    transpspar(1);

    for (kpos = 0; kpos < s[0].size;)
    {
        r = s[0].mat[kpos][0];
        for (lpos = 0; lpos < s[4].size;)
        {
            c = s[4].mat[lpos][0];

            tempk = kpos;
            templ = lpos;

            sum = 0;
                        
            while (tempk < s[0].size && s[0].mat[tempk][0] == r && templ < s[4].size&& s[4].mat[templ][0] == c)
            {
                if (s[0].mat[tempk][1] < s[4].mat[templ][1])
                {
                    tempk++;
                    // printf("something ");
                }
                else if (s[0].mat[tempk][1] > s[4].mat[templ][1])
                {
                    templ++;
                }
                else
                {
                    sum += s[0].mat[tempk++][2] * s[4].mat[templ++][2];
                }
            }
            if (sum != 0)
            {
                s[5].mat[s[5].size][0]  = r;
                s[5].mat[s[5].size][1]  = c;
                s[5].mat[s[5].size][2]  = sum;
                s[5].size++;
            }
            while (lpos < s[4].size  && s[4].mat[lpos][0] == c)
            {
                lpos++;
            }
        }
        while (kpos < s[0].size  && s[0].mat[kpos][0] == r)
        {
            kpos++;
        }
    }
    printf("\nProduct of of matrix 1 and 2 is\n");
    printspar(5);


} 

int main()
{    int r,c,v;
    printf("Enter row and coloumn of the matrix.\n");
    scanf("%d %d",&r,&c);
    printf("\nEnter matrix 1\n"); 
  for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {   scanf("%d",&v);
            if(v!=0){
                s[0].mat[s[0].size][0]=i;
                s[0].mat[s[0].size][1]=j;
                s[0].mat[s[0].size][2]=v;
                s[0].size++;
            }
        }
    printf("\nEnter matrix 2\n"); 
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {   scanf("%d",&v);
            if(v!=0){
                s[1].mat[s[1].size][0]=i;
                s[1].mat[s[1].size][1]=j;
                s[1].mat[s[1].size][2]=v;
                s[1].size++;
            }
        }
    printf("\nSparse of matrix 1 is\n");
    printspar(0);
    printf("\nSparse of matrix 2 is\n");
    printspar(1);
    printf("\nAdding 1 and 2 we get\n");
    addspar();
    if(r==c) multiply();
    else printf("They myst be square as the question wants matrix of same dimensionss.");
    
}
