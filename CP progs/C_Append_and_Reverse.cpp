#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;


void solve(){
  li n;
  cin>>n; 
  li a[n];
  lp(i,0,n) cin>>a[i];
  li i=0,j=n-1;
  while(i<j){
      reverse(a+i,a+j+1);
      reverse(a+i+1,a+j+1);
      i++;
      j--;
  }
  lp(i,0,n) cout<<a[i]<<" ";
  cout<<"\n";    
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