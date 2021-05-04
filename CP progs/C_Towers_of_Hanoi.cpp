#include <bits/stdc++.h>
#define li long long int
#define ld double
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


void solve(){
    li n;
    ld mx=0.00;
    cin>>n;
    li a[n];
    lp(i,0,n)cin>>a[i];
    lp(i,0,n){
        lp(j,i+1,n){
            ld hf=abs(a[j]-a[i])/(j-i);   
           if(hf>mx)mx=hf;        
        }
    }
    printf("%lf \n",mx);
    
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    li t=1;
    cin>>t;
    while(t--){
        solve();
   }

    return 0;
}