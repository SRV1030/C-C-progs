#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,x,y,mix=inf,miy=inf,maxx=-inf,maxy=-inf;
    cin>>n;
    while (n--)
    {
        cin>>x>>y;
        mix=min(mix,x);
        miy=min(miy,y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
    }
    
    
    cout<<max(maxx-mix,maxy-miy)<<"\n";
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