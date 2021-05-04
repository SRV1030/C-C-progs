#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    li u=0,d=0,l=0,r=0,n=s.size();
    lp(i,0,n){
        if(s[i]=='U') u++;
        else if(s[i]=='D') d++;
        else if(s[i]=='R') r++;
        else if(s[i]=='L') l++;    
    }
    li c=0;
    if(a==0)c++;
    else if(a>0 && r>=a)c++;
    else if(a<0 && l>=-a)c++;
    if(b==0)c++;
    else if(b>0 && u>=b)c++;
    else if(b<0 && d>=-b)c++;
    
    if(c==2)cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";    
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
