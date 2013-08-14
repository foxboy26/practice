#include <iostream>
#include <algorithm>
using namespace std;

class EllysTSP
{
public:
  int getMax(string places)
  {
    int c = 0, v = 0;

    for (int i = 0; i < places.length(); i++)
    {
      if (places[i] == 'C') c++;
      if (places[i] == 'V') v++;
    }

    if (c == v)
      return 2 * c;
    else
      return 2 * min(c, v) + 1;
  }
};

int main()
{
  EllysTSP t;

  cout << t.getMax("VVV") << endl;
  cout << t.getMax("VVVVCVV") << endl;
  cout << t.getMax("CVCVCVC") << endl;
  cout << t.getMax("V") << endl;
}
