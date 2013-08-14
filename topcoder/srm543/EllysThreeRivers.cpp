#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class EllysThreeRivers
{
  int w[3];
  int s[3];
  int walk;
  
  double solve(int idx, double rem)
  {
    if (idx == 3)
      return rem / walk;

    double ans = 2000000000;
    double l = 0.0, r = rem;
    for (int i = 0; i < 100; i++)
    {
      double m1 = l + (r - l) / 3.0;
      double m2 = r - (r - l) / 3.0;

      double res1 = sqrt(m1 * m1 + w[idx] * w[idx]) / s[idx] + solve(idx + 1, rem - m1);
      double res2 = sqrt(m2 * m2 + w[idx] * w[idx]) / s[idx] + solve(idx + 1, rem - m2);
      
      if (res1 < res2)
      {
        r = m2;
        ans = min(res1, ans);
      }
      else
      {
        l = m1;
        ans = min(res2, ans);
      }
    }

    return ans;
  }

public:
  double getMin(int length, int walk, vector <int> width, vector <int> swim)
  {
    this->walk = walk;

    for (int i = 0; i < 3; i++)
    {
      w[i] = width[i];
      s[i] = swim[i];
    }

    return solve(0, length);
  }
};
