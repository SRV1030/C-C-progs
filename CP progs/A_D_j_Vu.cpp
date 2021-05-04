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
    li l=0,r=s.length()-1;
    li n=r;    
    while(l<=r){
        if(s[l]!=s[r]) break;
        else if(s[l]==s[r] && s[l]!='a') break;
        l++;
        r--;           
    }
    if(l>r){
        cout<<"NO"<<"\n";
        return;
    }
    l=0,r=n+1;
    string s1=s+'a',s2='a'+s;
    cout<<"YES"<<"\n";
    while(l<=r){
        if(s1[l]!=s1[r]){
            cout<<s1<<"\n";
            return;
        } 
        else if(s2[l]!=s2[r]){
            cout<<s2<<"\n";
            return;
        }
        l++;
        r--;           
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
