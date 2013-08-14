#include <iostream>
#include <vector>
using namespace std;

class WorkingRabbits
{
public:
  double getEfficiency(vector <string> profit)
  {
    int n = profit.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        sum += profit[i][j] - '0';
      }
    }

    return sum * 1.0 / (n * (n - 1) / 2);
  }
};

int main()
{
  return 0;
}
