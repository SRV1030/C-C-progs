#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;

li po(li a,li b){
    li res=1;
    while(b>0){
        if(b%2)res=(res*a)%md;
        a=(a*a)%md;
        b/=2;
    }
    return res;
}

void solve(){
    li n,q;
    cin>>n>>q;
    vector<li>v(q);
    vector<char>c(q);
    lp(i,0,q)cin>>v[i];
    lp(i,0,q)cin>>c[i];
    map<li,set<char>>mp;
    lp(i,0,q) mp[v[i]].insert(c[i]);
    li ans=po(26,n-mp.size());
    for(auto i:mp){
        ans= ((ans%md)*((26-i.second.size())%md))%md;
    }
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
//    }

    return 0;
}
