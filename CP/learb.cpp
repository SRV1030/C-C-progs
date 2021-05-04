#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,m,mn=inf;
    cin>>n>>m;
    vector<li> a(n);
    vector<li> v(n+1,1);
    for(auto &it:a) cin>>it;
    n=unique(a.begin(),a.end())-a.begin();
    a.resize(n);
    for(int i=0;i<n;i++){
        v[a[i]]+=1;
    }
    v[a[0]]-=1;
    v[a[n-1]]-=1;
     lp(i,0,n){
        mn=min(mn,v[a[i]]);
    }
    cout<<mn<<"\n";
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
