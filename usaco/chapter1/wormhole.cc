/*
ID: foxboy21
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int X[13];
int Y[13];
int Next[13] = {0};
int Pair[13] = {0};

void print(int a[], int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

bool cycle() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int j = 1; j <= N; j++) {
            pos = Next[Pair[pos]];
        }
        if (pos != 0) {
            return true;
        }
    }
    return false;
}

int solve() {
    int total = 0;
    int i;

    // Find 1st unpaired worm.
    for (i = 1; i <= N; i++) {
        if (Pair[i] == 0) {
            break;
        }
    }

    // Check cycle if all worm are paired.
    if (i > N) {
        return cycle()? 1 : 0;
    }

    for (int j = i+1; j <= N; j++) {
        // Skip already paired worm.
        if (Pair[j] != 0) continue;

        Pair[i] = j;
        Pair[j] = i;
        total += solve();
        Pair[i] = 0;
        Pair[j] = 0;
    }

    return total;
}

int main()
{
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");

  fin >> N;
  for (int i = 1; i <= N; i++) {
    fin >> X[i] >> Y[i];
  }
  fin.close();

  // Build next right array.
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
        if (Y[i] == Y[j] && X[j] > X[i]) {
            if (Next[i] == 0 || X[j] < X[Next[i]]) {
                Next[i] = j;
            }
        }
    }
  }

  int total = solve();
  fout << total << "\n";
  fout.close();

  return 0;
}
