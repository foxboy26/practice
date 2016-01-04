/*
ID: foxboy21
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  string comet, group;

  fin >>  comet >> group;

  int comet_num = 1, group_num = 1;

  for(int i = 0; i < comet.length(); i++)
  {
    comet_num *= (comet[i] - 'A' + 1);
  }

  for(int i = 0; i < group.length(); i++)
  {
    group_num *= (group[i] - 'A' + 1);
  }
  
  fout << ((((group_num - comet_num) % 47) == 0)? "GO\n" : "STAY\n"); 

  fin.close();
  fout.close();

  return 0;
}
