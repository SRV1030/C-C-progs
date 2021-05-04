#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n;
   cin>>n;
   li x;
   set<li>s;
   map<li,li>mp;
   lp(i,0,n){
       cin>>x;
       mp[x]++;
       s.insert(x);
   }
   vector<li>v(s.begin(),s.end());
   if(v.size()==1){
       li ans=0;
       for(li i=mp[v[0]]-1;i>0;i--){
          ans+=i;
       }
       cout<<0<<" "<<ans<<"\n";
   }
   else{
       x=v.size();
       sort(v.begin(),v.end());
       li i=0,j=v.size()-1;
       li diff=v[j]-v[i];
       li c=0,p=0;
       while (i<j)
       {
           if(v[j]-v[i]==diff){
               c++;
               p+=(mp[v[i]]*mp[v[j]]);
           }
           i++;
           j--;
       }
       cout<<diff<<" "<<p<<"\n";       
   }
   
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
