#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;

void solve(){
    li n,mx=0,l=0,r=0;
    cin>>n;    
    vector<li>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
        l+=(1000-v[i]);
    }
    sort(begin(v),end(v));
    for(int i=n-1;i>=0;--i){
        r+=v[i];
        l-=(1000-v[i]);
        mx=max(mx,l*r);
    }
    cout<<mx<<"\n";
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