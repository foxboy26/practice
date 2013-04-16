/*
ID: foxboy21
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



bool operator< (const Interval& lhs, const Interval& rhs)
{
  return (lhs.l < rhs.l);
}

int main()
{
  ifstream fin("calfflac.in");
  ofstream fout("calfflac.out");

  char str[20000];
  char c;

  int p = 0;
  while ((c = fin.get()) != EOF)
  {
    if (c == '\n') continue;
    str[p++] = c;
  }

  for (int
  

  fin.close();
  fout.close();

  return 0;
}
