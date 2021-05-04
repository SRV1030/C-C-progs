#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li a,b,c,d;
   cin>>a>>b>>c>>d;   
   if(a>c){
       swap(a,c);
       swap(b,d);
   }
   if(c<=b) cout<<"Yes"<<"\n";
   else cout<<"No"<<"\n";
   
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
   // }

    return 0;
}
