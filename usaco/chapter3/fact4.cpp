/*
ID: foxboy21
PROG: fact4
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream fin("fact4.in");
  ofstream fout("fact4.out");

  int N;
  fin >> N;
  int res = 1;
  for (int i = 1; i <= N; i++) {
    res *= i;
    while (res % 10 == 0) {
      res /= 10;
    }

    res %= 1000000;
  }

  fout << res % 10 << endl;

  fin.close();
  fout.close();

  return 0;
}
