#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


void solve(){
    string s,a,ans;
    cin>>a>>s;
    int i,j;
    for( i=a.size()-1,j=s.size()-1;i>=0 && j>=0;i--,j--){
        string t;
        t+=s[j];
        if (j-1>=0 && (a[i]-'0')>stoi(t)) t.insert(t.begin(),s[--j]);
        int d=stoi(t);
        if(d-a[i]+'0'>=10){
            cout<<-1<<"\n";
            return;
        }
        int v=d-a[i]+'0';
        ans+=to_string(v);
    } 
    if(i>=0){
        cout<<-1<<"\n";
        return;
    }   
    if(j>=0)while (j>=0){
        ans.push_back(s[j]);
        j--;
    }
    
    reverse(ans.begin(),ans.end());
    j=0;
    while(ans[j]=='0')j++;
    if(j==ans.size()) cout<<0<<"\n";
    else cout<<ans.substr(j)<<"\n";
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