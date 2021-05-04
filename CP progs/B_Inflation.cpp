#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,k;
    cin>>n>>k;
    li a[n];
    lp(i,0,n){
        cin>>a[i];       
    }
    li ans=0,psum=a[0];
    lp(i,1,n){
        ans=max(ans,(100*a[i]-k*psum+k-1)/k);
        psum+=a[i];
    }
  cout<<ans<<"\n";
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
