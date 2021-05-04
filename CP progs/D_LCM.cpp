#include <bits/stdc++.h>
#define li  long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n,x,a;
   vector<li>v;
   cin>>n>>x;
   lp(i,0,n){
       cin>>a;      
       if(x%a==0){
           v.push_back(a);
       }
   }  
   if(v.size()==0)cout<<"NO"<<"\n";
   else{
       li l=1;
       lp(i,0,v.size()){
           l=(l*v[i])/__gcd(l,v[i]);
       }
          if(l==x) cout<<"YES"<<"\n";   
          else cout<<"NO"<<"\n";
   }
    
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