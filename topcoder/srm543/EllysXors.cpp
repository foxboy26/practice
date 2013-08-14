#include <iostream>
#include <algorithm>
using namespace std;

class EllysXors
{
private:
  long long getXor1N(long long N)
  {
    if (N % 4 == 0)
      return N;
    else if (N % 4 == 1)
      return 1;
    else if (N % 4 == 2)
      return N + 1;
    else
      return 0;
  }
public:
  long long getXor(long long L, long long R)
  {
    return getXor1N(L - 1) ^ getXor1N(R);
  }
};

int main()
{
  EllysXors t;

  cout << t.getXor(3, 10) << endl;
  cout << t.getXor(5, 5) << endl;
  cout << t.getXor(666, 1337) << endl;
}
