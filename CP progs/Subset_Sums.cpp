#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;
void SubSum(li a[],li s,li e,vector<li> &v){
    li n= e-s+1;
    lp(i,0,1<<n){
        li sum=0;
        li x=i;
        li j=s;
        while(x){
            if(x&1) sum+=a[j];
            j++;
            x=x>>1;
        }
        v.push_back(sum);
    }
}
void solve(){
   li n,x,y;
   cin>>n>>x>>y;
   li a[n];
   lp(i,0,n) cin>>a[i];
   vector<li>v1,v2;
   SubSum(a,0,(n/2)-1,v1);
   SubSum(a,n/2,n-1,v2);
   sort(v2.begin(),v2.end());
   li c=0;
//    lp(i,0,v2.size()) cout<<v2[i]<<" ";
   lp(i,0,v1.size()){
       li l= lower_bound(v2.begin(),v2.end(),x-v1[i])-v2.begin(); 
       li h= upper_bound(v2.begin(),v2.end(),y-v1[i])-v2.begin();
       c+=(h-l);
   }

    cout<<c<<"\n";
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