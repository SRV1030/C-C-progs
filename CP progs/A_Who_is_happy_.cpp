#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    char s;
    li n,a=0,b=0;
    cin>>n;
    lp(i,0,n){
        cin>>s;
        if(s=='A') a++;
        else if(s=='B') b++;
    }
    if(a>b) cout<<"Anirban";
    else  if(a<b) cout<<"Biswa";
    else cout<<"Samay"; 
    cout<<"\n";
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