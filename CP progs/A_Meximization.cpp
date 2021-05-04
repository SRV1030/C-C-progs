#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;
void solve(){
  li n;
  cin>>n;
  map<li,li>mp;
  set<li>s;
  lp(i,0,n){
      li x;
      cin>>x;
      s.insert(x);
      mp[x]++;
  } 
  for(auto i:s) cout<<i<<" ";
  for(auto i:mp){
      lp(z,1,i.second) cout<<i.first<<" ";
  }
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