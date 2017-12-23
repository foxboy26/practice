/*
ID: foxboy21
PROG: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void print(int a[], int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int pow2(int a) {return a*a;}

int main()
{
  ifstream fin("skidesign.in");
  ofstream fout("skidesign.out");

  int N;
  int h[1001];

  fin >> N;
  for (int i = 0; i < N; i++) {
    fin >> h[i];
  }

  fin.close();

  sort(h, h+N);

  //print(h, N);

  int total_min = INT_MAX;
  for (int i = 0; i <= h[N-1]-17; i++) {
    int total = 0;
    for (int j = 0; j < N; j++) {
        if (h[j] < i) {
            total += pow2(i - h[j]);
        }
        if (h[j] > i+17) {
            total += pow2(h[j] - i - 17);
        }
    }
    total_min = min(total_min, total);
  }

  fout << total_min << "\n";
  fout.close();

  return 0;
}
