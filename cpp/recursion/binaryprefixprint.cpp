//print all the bits of length n such that all the prefix formed have 1x>0s

#include <bits/stdc++.h>
using namespace std;
vector < string > binary(int n,int O,int Z,string s ,vector<string>v)
{
  if (n == 0){
      v.push_back (s);
      return v;
    }
    string s1 = s;
    s1.push_back ('1');
    v = binary(n-1,O+1,Z,s1,v);
  if(Z<O)
    { string s2 = s;
      s1.push_back ('0');
      v = binary(n-1,O,Z+1,s2,v);
    }
    return v;
}

int main ()
{   int n=5;
    string s=" ";
  std::vector < string > v;
  v = binary(n,0,0,s,v);
  for (auto i : v) {
     std::cout << i << std::endl;
  }

  return 0;
}
