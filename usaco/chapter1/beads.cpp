/*
ID: foxboy21
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream fin("beads.in");
  ofstream fout("beads.out");
 
  int len;
  string beads;

  fin >> len;
  fin >> beads;

  beads.append(beads);

  int max_beads = 0;
  for (int i = 0; i < len; i++)
  {
    int cur_beads = 0;
    int s = i, e = i + len - 1;
    char color;
   
    while(s <= e && beads[s] == 'w')
    {
      cur_beads++;
      s++;
    }
    color = beads[s];
    while (s <= e && (beads[s] == 'w' || beads[s] == color))
    {
      cur_beads++;
      s++;
    }

    while(s <= e && beads[e] == 'w')
    {
      cur_beads++;
      e--;
    }
    color = beads[e];
    while (s <= e && (beads[e] == 'w' || beads[e] == color))
    {
      cur_beads++;
      e--;
    }

    max_beads = max(cur_beads, max_beads);
  }

  fout << max_beads << "\n";

  fin.close();
  fout.close();

  return 0;
}
