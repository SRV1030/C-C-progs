#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n;
   cin>>n;
   string a,b;
   cin>>a>>b;
   if(a==b){
       cout<<0<<"\n";
       return;
   }
   vector<li>res;
   lp(i,0,n){
       if(a[i]!=b[i]){
           if(i>0) res.push_back(i+1);
           res.push_back(1);
           if(i>0) res.push_back(i+1);
       }
   }
   cout<<res.size()<<" ";
   lp(i,0,res.size())cout<<res[i]<<" ";
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
