#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,k,ans=0;
    cin>>n>>k;
    vector<li>pos,neg;
    lp(i,0,n){
        li x;
        cin>>x;
        if(x>=0)pos.push_back(x);
        else if(x<0) neg.push_back(abs(x));
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    if(!pos.empty())for(int i=pos.size()-1;i>=0;i-=k)ans+=2*pos[i];
    if(!neg.empty())for(int i=neg.size()-1;i>=0;i-=k)ans+=2*neg[i];
    li mxd=pos.empty()?neg[neg.size()-1]:neg.empty()?pos[pos.size()-1]:max(neg[neg.size()-1],pos[pos.size()-1]);
    cout<<ans-mxd<<"\n";    
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
