#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n;
   cin>>n;
   string x;
   cin>>x;
   li a[27]={0};
   lp(i,0,n){       
       a[x[i]-'a']+=1;       
   }
   li ans=0;
   lp(i,0,27){
       if(a[i]%2==0) ans+=a[i];
       else if(a[i]>0) ans+=(a[i]-1);
    // cout<<a[i]<<" ";
   }
   if((n-ans-1)>=0)cout<<n-ans-1<<"\n";
   else cout<<n-1<<"\n";
//    else{
//        li c=0,m1;
//        lp(i,0,27){
//        if(a[i]==1) c++;

//     }
//     if(n-c>0)cout<<c+1<<"\n";
//     else cout<<n-1<<"\n";
//    }

   
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
