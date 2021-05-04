#include <bits/stdc++.h>
#define li unsigned long long int
#define ld long double
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    ld n,b,c=0,f=0,s=0;
    ld r,g;
    cin>>n>>g>>b;
    vector<ld>v;
    vector<ld>::iterator lb;
    lp(i,0,n) cin>>v[i];
    li mn=*min_element(v.begin(),v.end());    
    if(b<mn) cout<<"-1";
    else
    {
        while (r<g)
        {
           lb= lower_bound(v.begin(), v.end(), b);           
           if(lb==v.end()||(lb-v.begin()) ==b){
               if(r<g)f=1;
               break;
           }
           c+=1;
           s+=(lb-v.begin())+400;
           r=s/c;       

        }
        
    }
    if(f)cout<<-1<<"\n";
    else
    {
        cout<<c<<"\n";
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