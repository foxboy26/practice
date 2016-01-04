#include <iostream>
using namespace std;

int heavy(int num, int dp[][83], int dp2[])
{
  // store each digit into split array
  int split[9 + 2];
  int d = 0;
  while (num > 0)
  {
    d++;
    split[d] = num % 10;
    num /= 10;
  }

  int count = 0;
  int sum = 0;
  for (int i = d; i >= 1; i--)
  {
    for (int l = 0; l < split[i]; l++)
    {
      // if the first digit is 0
      if (i == d && l == 0)
      {
        count += dp2[i-1];
      }
      else
      {
        for (int j = 0; j <= (i - 1) * 9; j++) {
          if (l + j + sum > d * 7)
          {
            count += dp[i - 1][j];
          }
        }
      }
    }
    sum += split[i];
  }

  // last one
  if (sum > d * 7)
  {
    count++;
  }
  
  return count;
}

int main()
{
  int dp[9 + 2][9 * 9 + 2] = {0};

  // dp[i][j] := # of i-digits number with digit sum to j
  dp[0][0] = 1;
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= i * 9; j++)
    {
      for (int k = 0; k <= j && k < 10; k++)
      {
        dp[i][j] += dp[i - 1][j - k]; 
      }
    }
  }

  int dp2[9 + 2] = {0};
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= i * 9; j++)
    {
      if (j > 7 * i)
      {
        dp2[i] += dp[i][j];
      }
    }
    dp2[i] += dp2[i - 1];
  }

  int a, b;
  cin >> a >> b;
  cout << heavy(b, dp, dp2) - heavy(a - 1, dp, dp2) << endl;
  
  return 0;
}
