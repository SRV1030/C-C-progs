#include <bits/stdc++.h>
using namespace std;
vector < string > balancedP(int O,int C,string Op ,vector<string>v)
{
  if (C == 0 && O== 0){
      v.push_back (Op);
      return v;
    }
  if (O!=0)
    { string O1 = Op;
      O1.push_back ('(');
      v = balancedP(O-1,C,O1,v);
    }
  if(C>O)
    { string O1 = Op;
      O1.push_back (')');
      v = balancedP(O,C-1,O1,v);
    }
    return v;
}

int main ()
{ int n=3;
    string s=" ";
  std::vector < string > v;
  v = balancedP(n,n,s,v);
  for (auto i : v) {
     std::cout << i << std::endl;
  }

  return 0;
}
