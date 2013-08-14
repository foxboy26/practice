#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class PatrolRoute
{
  int minT, maxT, X, Y;
  bool h[4000], v[4000];
  int p[3][2];

  void recurse(int l, int& count)
  {
    if (l == 3)
    {
      int len = 0;
      for (int i = 0; i < 3; i++)
      {
        for (int j = 0; j < 2; j++)
        {
          len += abs(p[i][j] - p[(i + 1) % 3][j]);
        }
      }

      if (len >= minT && len <= maxT)
      {
        count++;
      }
      return;
    }

    for (int i = 0; i < X; i++)
    {
      for (int j = 0; j < Y; j++)
      {
        if (!h[i] && !v[j])
        {
          h[i] = v[j] = true;

          p[l][0] = i;
          p[l][1] = j;

          recurse(l + 1, count);

          h[i] = v[j] = false;
        }
      }
    }
  }
public:
  int countRoutes(int X, int Y, int minT, int maxT)
  {
    this->X = X;
    this->Y = Y;
    this->minT = minT;
    this->maxT = maxT;

    for (int i = 0; i < 4000; i++)
    {
      h[i] = v[i] = false;
    }
   
    int count = 0;

    recurse(0, count);

    return (count / 6);
  }
};

int main()
{
  PatrolRoute t;
  cout << t.countRoutes(3, 3, 1, 20000) << endl;
  return 0;
}
