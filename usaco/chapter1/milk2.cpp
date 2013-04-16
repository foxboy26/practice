/*
ID: foxboy21
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Interval
{
  int l;
  int r;
};

bool operator< (const Interval& lhs, const Interval& rhs)
{
  return (lhs.l < rhs.l);
}

int main()
{
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");

  int n;
  Interval range[5000];

  fin >> n;
  for (int i = 0; i < n; i++)
  {
    fin >> range[i].l >> range[i].r;
  }

  sort(range, range + n);

  int left = range[0].l, right = range[0].r;
  int long_continue = right - left, long_idle = 0;
  for (int c = 1; c < n; c++)
  {
    if (range[c].l <= right)
    {
      right = max(range[c].r, right);
    }
    else
    {
      long_continue = max(right - left, long_continue);
      long_idle = max(range[c].l - right, long_idle);
      left = range[c].l;
      right = range[c].r;
    }
  }

  fout << long_continue << " " << long_idle << "\n";

  fin.close();
  fout.close();

  return 0;
}
