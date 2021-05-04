#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;

void solve(){
    // li n,c=0;
    // cin>>n;
    // string s;
    // cin>>s;
    // lp(i,0,n)
    //     c+= (s[i]=='1');
    // if(c%2==1 || s[0]=='0' || s.back()=='0'){
    //     cout<<"NO\n";
    //     return;
    // }
    // string s1,s2;
    // int k=0;
    // bool f=false;
    // lp(i,0,n){
    //     if(s[i]=='1'){
    //         s1.push_back(2*k<c? '(':')');
    //         s2.push_back(s1.back());
    //         k++;
    //     }
    //     else{
    //         s1.push_back(f? '(':')');
    //         s2.push_back(!f? '(':')');
    //         f=!f;
    //     }
    // }              
    // cout<<"YES\n"<<s1<<"\n"<<s2<<"\n";
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (s[i] == '1');
    }
    if(cnt % 2 == 1 || s[0] == '0' || s.back() == '0') {
        cout << "NO\n";
        return;
    }
    string a, b;
    int k = 0;
    bool flip = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            a.push_back(2 * k < cnt ? '(' : ')');
            b.push_back(a.back());
            k++;
        }else {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n" << a << '\n' << b << '\n';
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
