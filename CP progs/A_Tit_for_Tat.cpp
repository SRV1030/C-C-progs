#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;

void solve(){
    li n,k;
    cin>>n>>k;
    li a[n];
    lp(i,0,n) cin>>a[i];
    lp(i,0,n-1){
        
        if(k>=a[i]){            
            k-=a[i];
            a[n-1]+=a[i];
            a[i]=0;           
        }
        else{
            a[i]-=k;
            a[n-1]+=k;
            k=0;
        }
        
        if(k<=0) break;
    }
    lp(i,0,n) cout<<a[i]<<" ";
    cout<<"\n";
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
