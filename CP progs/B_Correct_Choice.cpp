#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


void solve(){
    li n;
    cin>>n;
    li a[n];
    lp(i,0,n) cin>>a[i];
    li mx=ninf,k=0;
    lp(i,1,n+1){
        li c=0;
        for(li j=i;j<n+1;j+=i){
            c+=a[j-1];
        }
        if(c>mx){
            mx=c;
            k=i;
        }
    }

    
    cout<<k<<'\n';
    
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
