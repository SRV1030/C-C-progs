// sample: ABC:
// A_B_C
// A_BC
// AB_C
// ABC

#include <bits/stdc++.h>
using namespace std;
void Printwithspace(string I,string O){
    if(I.length()==0){
      std::cout << O << std::endl;
      return;
    }
    string O1=O;
    string O2=O;
    O1.push_back('_');
    O1.push_back(I[0]);
    O2.push_back(I[0]);
    I.erase(I.begin()+0);
    Printwithspace(I,O1);
    Printwithspace(I,O2);
    return;
}
int main()
{   string I="SUB";
    string o;
    o.push_back(I[0]);
    I.erase(I.begin()+0);
    Printwithspace(I,o);

    return 0;
}
