#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
bool isPowerOfTwo(li n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
void solve(){
    li n;
    cin>>n;
    if(isPowerOfTwo(n))cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";    
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