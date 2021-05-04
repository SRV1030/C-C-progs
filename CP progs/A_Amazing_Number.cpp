#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
  string s;
  li c=1;
   cin>>s;   
   lp(i,0,s.length()-1){
       if(s[i]==s[i+1]) c++;
       else{
           if(c>=3){
               cout<<"Yes"<<"\n";
               return;
           }else{
               c=1;
           }
       }
   } 
   if(c>=3) cout<<"Yes"<<"\n";
   else cout<<"No"<<"\n";
         

    
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