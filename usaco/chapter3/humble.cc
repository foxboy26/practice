/*
ID: foxboy21
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ifstream fin("humble.in");
    ofstream fout("humble.out");

    int N, K;
    fin >> K >> N;

    int P[101];
    for (int i = 1; i <= K; i++) {
        fin >> P[i];
    }
    sort(P, P + K);

    S[0] = 1;
    int s = 0;
    while (s <= N) {
        for (int i = 1; i <= K; i++) {
            for (int j = 0; j <= s; j++) {
                
            }
        }
    }

    auto it = s.begin();
    for (int i = 0; i < N; i++) {
        it++;
    }

    fout << *it << "\n";

    return 0;
}
