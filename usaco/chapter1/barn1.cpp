/*
ID: foxboy21
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");
 
  int stalls[200];
  int M, S, C;

  fin >> M >> S >> C;
  for (int i = 0; i < C; i++)
  {
    fin >> stalls[i];
  }

  if (M >= C)
  {
    fout << C << "\n";
  }
  else
  {
    sort(stalls, stalls + C);

    int diff[200];
    for (int i = 0; i < C - 1; i++)
    {
      diff[i] = stalls[i + 1] - stalls[i] - 1;
    }

    sort(diff, diff + C - 1);

    int result = 0;
    for (int i = 1; i < M; i++)
    {
      result += diff[C - 1 - i];
    }

    fout << stalls[C - 1] - stalls[0] + 1 - result << "\n";
  }

  fin.close();
  fout.close();

  return 0;
}
