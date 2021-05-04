#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
li Odd(li n) 
{  li cnt=0;
    if (n%2 != 0) 
        return cnt; 
    while (n%2 == 0) { 
        n /= 2; 
        cnt++; 
    } 
  
    return cnt; 
} 
void solve(){
  li n;
  cin>>n; 
  li a[n];
  lp(i,0,n) cin>>a[i];
  li mn=Odd(a[0]);
  lp(i,1,n){
      mn=min(mn,Odd(a[i]));
  }
  cout<<mn<<"\n";
    
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