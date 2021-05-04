#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n;
   cin>>n;
   li a[n],c=0;
   lp(i,0,n) cin>>a[i];
   li m[n];
   m[n-1]=a[n-1];
   rlp(i,n-2,0){
        if(m[i+1]<a[i]) m[i]=m[i+1];
        else m[i]=a[i];
   }
   lp(i,0,n){
       if(a[i]>m[i]) c++;
    //    cout<<m[i]<<" ";
   }
   cout<<c<<"\n";
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

