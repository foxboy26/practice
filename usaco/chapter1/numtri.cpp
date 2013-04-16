/*
ID: foxboy21
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  
  int tri[1000 * 1001 / 2];
  int row;

  fin >> row;

  for (int i = 0; i < row * (row + 1) / 2; i++)
  {
    fin >> tri[i];
  }

  for (int i = 2; i <= row; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (j == 0)
      {
        tri[i * (i - 1) / 2 + j] += tri[(i - 1) * (i - 2) /2 + j];
      }
      else if (j == i - 1)
      {
        tri[i * (i - 1) / 2 + j] += tri[i * (i - 1) /2 - 1];
      }
      else
      {
        tri[i * (i - 1) / 2 + j] += max(tri[(i - 1) * (i - 2) / 2 + j], tri[(i - 1) * (i - 2) / 2 + j - 1]);
      }
    }
  }

  int largest_sum = 0;
  for (int i = 0; i < row; i++)
  {
    largest_sum = max(largest_sum, tri[row * (row - 1) / 2 + i]);
  }

  fout << largest_sum << "\n";

  fin.close();
  fout.close();

  return 0;
}
