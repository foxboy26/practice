/*
ID: foxboy21
PROG: rect1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct paper
{
  int llx;
  int lly;
  int urx;
  int ury;
  int color;
};

int main()
{
  ifstream fin("rect1.in");
  ofstream fout("rect1.out");
  
  int A, B, N;
  paper c[25000];

  fin >> A >> B >> N;

  for (int i = 0; i < N; i++)
  {
    fin >> p[i].llx >> p[i].lly >> p[i].urx >> p[i].ury >> p[i].color;   
    for (int i = 0
  }

  

  fin.close();
  fout.close();

  return 0;
}
