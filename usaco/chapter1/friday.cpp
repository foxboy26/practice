/*
ID: foxboy21
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Day {SUN, MON, TUE, WED, THU, FRI, SAT};
enum Month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main()
{
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  
  int range;
  fin >> range;

  int freq[7] = {0, 0, 0, 0, 0, 0, 0};
  int day = 13;

  for (int i = 1900; i < 1900 + range; i++)
  {
    for (int j = 0; j < 12; j++)
    {
      freq[day % 7]++;  
      if (j == APR || j == JUN || j == SEP || j == NOV)
      {
        day += 30;
      }
      else if (j == FEB)
      {
        day += ((((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))? 29 : 28);
      }
      else
      {
        day += 31;
      }
    }
  }

  fout << freq[SAT] << " " << freq[SUN] << " " << freq[MON] << " " << freq[TUE] << " " << freq[WED] << " " << freq[THU] << " " << freq[FRI] << "\n";

  fin.close();
  fout.close();

  return 0;
}
