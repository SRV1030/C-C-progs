#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
  li n,s;
  cin>>n>>s; 
  if(n==1) cout<<s<<"\n";
  else{      
    if(n%2) n=n-(n/2);
    else n=n-(n/2-1);
    cout<<s/n<<"\n";
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