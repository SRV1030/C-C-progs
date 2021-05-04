#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,ans;
    cin>>n;
    li a[n];
    lp(i,0,n)cin>>a[i]; 
    ans=1;
    lp(i,0,n) ans = (ans * a[i])/(__gcd(ans, a[i]));
    
    cout<<ans<<"\n";
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