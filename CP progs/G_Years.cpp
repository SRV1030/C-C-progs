#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n;
   cin>>n;
   map<li,li>mp;
   lp(i,0,n){
       li x,y;
       cin>>x>>y;
       mp[x]++;mp[y]--;
   }
   li a=0,b=0,s=0;
   for(auto i:mp){
       s+=i.second;
       if(s>b){b=s;a=i.first;}
   }
   cout<<a<<" "<<b<<"\n";

}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
    //}

    return 0;
}
