#include <bits/stdc++.h>
#define li long long int
using namespace std;

void solve(){
   li f1=0,f2=0,count=0,i=0,m=0,cl=0,n,k;
   string S;
    cin>>n>>k;
    cin>>S;

    while(i<n && m<n) {
       if(S[i]=='I' && f1==0){
           f1=1;
       }
       else if(S[m]=='M' && f2==0){
           f2=1;
       }
       else if(S[i]=='X'||S[m]=='X') {
           f1=0;
           f2=0;
       }
       if(f1 && f2){
           for(li z=(m<i?m:i);z<(m>i?m:i);z++) if(S[z]==':')cl++;
           li p=(k+1-abs(m-i)-cl);
           if (p>0){
              count+=1;
           }
           else{
               if(m>i) {
                   f1=0;
                   i++;
               }
               else if(m<i){
                   f2=0;
                   m++;
               }
           }
       }
       else{
           if(f1==0)i++;
           if(f2==0)m++;
       }

    }
    std::cout << count << std::endl;
}

int main()
{
    li t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
