#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;

void solve(){
    string s;
    cin>>s;
    li n=s.length();
    li j=n-1;
    li i=0;
    for(;i<n;i++)
        if(s[i]!='0')break;

    for(;j>=0;j--)
        if(s[j]!='0')break;

    // cout<<i<<" "<<j<<"\n";
    while(i<j){
        if(s[i]!=s[j]){
            cout<<"No"<<"\n";
            return;
        }
        i++;
        j--;
    }
    cout<<"Yes"<<"\n";
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    li t=1;
    // cin>>t;
    while(t--){
        solve();
   }

    return 0;
}
