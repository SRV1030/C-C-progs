#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li t,p=7;
   cin>>t;
   string ts,ps="BAZINGA";
    cin>>ts;   
   li i=0,j=0;
   li c=0;
   while (i<t && j<p){
       if(ts[i]==ps[j]){
           i++;
           j++;
           c+=1;
       }
       else i++;  
      
   }
   if(c==p) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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