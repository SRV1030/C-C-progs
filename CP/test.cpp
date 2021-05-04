#include <bits/stdc++.h>
#define li long long int
using namespace std;
const li inf = 1e18+7;
void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end(),greater<char>());
    cout<<s[0];
    for(li i=1;i<s.length();i++){
        if(s[i]==s[i-1]) cout<<s[i];
        else break;
    }
    cout<<"\n";
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
   // }

    return 0;
}
