/*
ID: foxboy21
PROG: agrinet
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream fin("agrinet.in");
  ofstream fout("agrinet.out");

  int N;
  int w[101][101];
  fin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> w[i][j];
    }
  }

  int cost = 0;
  int dist[101] = {100000 + 1}; // max dist < 100,000
  int src[101] = {-1};
  bool intree[101] = {false};

  int tree_size = 1;
  intree[0] = true;
  for (int j = 1; j < N; j++) {
    src[j] = 0;
    dist[j] = w[0][j];
  }

  while (tree_size < N) {
    // Find the node |n| with minimum distance to the tree.
    int min_dist = 100000 + 1;
    int n = -1;
    for (int i = 0; i < N; i++) {
      if (!intree[i] && dist[i] < min_dist) {
        n = i;
        min_dist = dist[i];
      }
    }

    if (n == -1)
      cout << "ERROR!!!!";

    // Add to the tree.
    tree_size++;
    cost += min_dist;
    intree[n] = true;

    // Update the distance to the tree of all neighbours of |n|.
    for (int i = 0; i < N; i++) {
      if (i == n)
        continue;

      if (w[i][n] < dist[i]) {
        dist[i] = w[i][n];
        src[i] = n;
      }
    }
  }

  fout << cost << endl;

  fin.close();
  fout.close();

  return 0;
}
