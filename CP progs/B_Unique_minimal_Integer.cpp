#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n;
    cin>>n;
    unordered_map<li,pair<li,li>>mp;
    vector<li>x(n);
    lp(i,0,n){
        cin>>x[i];
        mp[x[i]].first=i;
        mp[x[i]].second++;
    }
    li mn=inf,op=-1;
    for(auto i:mp){
        if(i.second.second==1){
            if(mn>i.first){
                mn=i.first;
                op=i.second.first+1;
            }
        }
    }
    cout<<op<<"\n";
    
    
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
