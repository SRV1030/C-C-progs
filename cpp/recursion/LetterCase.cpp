// sample: A1b:
// a1b
// A1b
// a1B
// A1B

#include <bits/stdc++.h>
using namespace std;
vector < string > Printwithspace (string I, string O,vector<string>v)
{
  if (I.length () == 0)
    {
      v.push_back (O);
      return v;
    }
  if (isalpha (I[0]))
    {
      string O1 = O;
      string O2 = O;
      O1.push_back (toupper (I[0]));
      O2.push_back (tolower (I[0]));
      I.erase (I.begin () + 0);
      v = Printwithspace (I, O1,v);
      v = Printwithspace (I, O2,v);
      return v;
    }
  else
    {
      string O1 = O;
      O1.push_back (I[0]);
      I.erase (I.begin () + 0);
      v = Printwithspace (I, O1,v);
      return v;
    }
}

int main ()
{
  string I = "S1b2";
  string o = " ";
  std::vector < string > v;
  v = Printwithspace (I, o, v);
  for (auto i : v) {
     std::cout << i << std::endl;
  }

  return 0;
}
