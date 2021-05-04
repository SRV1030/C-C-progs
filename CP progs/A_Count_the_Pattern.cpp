#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n,c=0;
   cin>>n;
   li a[n+1][n+1];
   lp(i,0,n)
       lp(j,0,n) cin>>a[i][j];

   lp(i,0,n){
       lp(j,0,n){
           if(j-1>=0 && i+1<n && j+1<n && i+2<n){
              if( a[i][j]==1 && a[i+1][j-1]==1 &&a[i+1][j]==0 && a[i+1][j+1]==1 && a[i+2][j]==1) c++;
           }
       }
   }

    
    cout<<c<<"\n";
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
   // }

    return 0;
}