/*
ID: foxboy21
PROG: milk
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
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  

  fin.close();
  fout.close();

  return 0;
}
