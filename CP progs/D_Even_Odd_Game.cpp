#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n;
   cin>>n;
   li a[n];
   li e=0,o=0;
   lp(i,0,n){
       cin>>a[i];
   }
  sort(a,a+n,greater<int>());
  lp(i,0,n){
      if(i%2==0){
        if(a[i]%2) e=e;
        else e+=a[i];
      }
      else{          
        if(a[i]%2) o+=a[i];
        else o=o;      
      }
  }
  if(e==o)cout<<"Tie"<<"\n";
  else if(e>o) cout<<"Alice"<<"\n";
  else  cout<<"Bob"<<"\n";

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
