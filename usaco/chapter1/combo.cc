/*
ID: foxboy21
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Intvl {
    int low;
    int high;
};


int intersect(const Intvl& lhs, const Intvl& rhs) {
    if ((lhs.low == 0 && lhs.high == 0) || (rhs.low == 0 && rhs.high == 0)) {
        return 0;
    }
    int l = max(lhs.low, rhs.low), r = min(lhs.high,rhs.high);
    cout << "value: " << (l <= r? (r-l+1) : 0);
    return l <= r? (r-l+1) : 0;
}

void print(const Intvl& i) {
    cout << "low: " << i.low << " high: " << i.high << std::endl;
}

int main()
{
  ifstream fin("combo.in");
  ofstream fout("combo.out");

  int f[3];
  int m[3];
  int v;
  int N;
    
  fin >> N;
  if (N <= 5) {
      fin.close();
      fout << N * N * N << "\n";
      fout.close();
      return 0;
  }

  for (int i = 0; i < 3; i++) {
      fin >> f[i];
  }
  for (int i = 0; i < 3; i++) {
      fin >> m[i];
  }

  fin.close();

  int dup = 1;
  for (int i = 0; i < 3; i++) {
    Intvl a = {(f[i] - 2 <= 0)? f[i]-2+N : f[i]-2, (f[i] + 2 > N)? f[i]+2-N : f[i]+2};
    Intvl b = {(m[i] - 2 <= 0)? m[i]-2+N : m[i]-2, (m[i] + 2 > N)? m[i]+2-N : m[i]+2};
    Intvl c = {0, 0};
    Intvl d = {0, 0};
    //print(a);
    //print(b);
    if (a.low > a.high) {
        c.low = a.low;
        c.high = N;
        a.low = 1;
    }
    if (b.low > b.high) {
        d.low = b.low;
        d.high = N;
        b.low = 1;
    }
    //print(a);
    //print(b);
    //print(c);
    //print(d);
    int v = (intersect(a, b) + intersect(a, d) + intersect(c, b) + intersect(c, d));
    dup *= v;

//    cout << "hahahaha: " << v << std::endl;
  }
  fout << 250 - dup << "\n";

  fout.close();

  return 0;
}
