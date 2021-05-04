#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
bool isPrime(li n) { 
    if (n <= 1)  return false;
    if(n==2 || n==3 || n==5 || n==7||n==11||n==13) return true;
    if (n%2 == 0 || n%3 == 0) return false; 
    for (li i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false;   
    return true; 
}
void solve(){
    li n;
    cin>>n;
    li a=n+1;
    while (!isPrime(a)) a++;
    li b=a+n;
    while (!isPrime(b)) b++;    
    cout<<a*b<<"\n";
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
