#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  unsigned int n;

  int s, d;
  while (cin >> n)
  {
    if (n == 0)
      break;

    d = n % 10;
    if (d == 2 || d == 3 || d == 7 || d == 8)
    {
      cout << "no" << endl;
    }
    else
    {
      s = sqrt(n);
      if (s * s == n)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }

  return 0;
}
