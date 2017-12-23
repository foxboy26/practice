/*
ID: foxboy21
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");

  int N, K;
  int stamp[50];
  int dp[2000000] = {0};
  int min_s = 10001;

  fin >> K >> N;
  for (int i = 0; i < N; i++)
    fin >> stamp[i];

  dp[0] = 0;
  int i = 0;
  while (dp[i] <= K) {
    ++i;
    int min_n = K;
    for (int j = 0; j < N; j++) {
      if (i - stamp[j] >= 0 && dp[i-stamp[j]] < K) {
        min_n = min(dp[i-stamp[j]], min_n);
      }
    }
    dp[i] = min_n + 1;
  }

  fout << i - 1 << endl;

  fin.close();
  fout.close();

  return 0;
}
