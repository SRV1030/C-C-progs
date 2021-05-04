#include <bits/stdc++.h>
using namespace std;
void subset(int ind,string I,string O){
    if(ind==I.length()){
      std::cout << O << std::endl;
      return;
    }
    subset(ind+1,I,O+I[ind]);
    subset(ind+1,I,O);
    return;
}
int main()
{
    subset(0,"SUB"," ");

    return 0;
}
