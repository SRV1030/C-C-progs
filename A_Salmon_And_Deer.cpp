#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n,k;
   cin>>n>>k;
   li a[n];
   lp(i,0,n)cin>>a[i];
   if(*max_element(a,a+n)>=k)cout<<1<<"\n";
   else cout<<0<<"\n";
   
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
