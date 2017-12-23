/*
ID: foxboy21
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Pattern {
    string str;
    long long int freq;
};

bool compare(const Pattern& lhs, const Pattern& rhs) {
    if (lhs.freq == rhs.freq) {
        if (lhs.str.length() != rhs.str.length()) {
            return lhs.str.length() < rhs.str.length();
        } else {
            return lhs.str < rhs.str;
        }
    }
    return lhs.freq > rhs.freq;
}

int main() {
    ifstream fin("contact.in");
    ofstream fout("contact.out");

    int A, B, N;
    char s[200001];
    fin >> A >> B >> N;
    int len;
    for (len = 0; !fin.eof(); len++) {
        fin >> s[len];
    }

    Pattern p[9000];
    for (int i = 0; i < 9000; i++) { p[i].str="";p[i].freq = 0;}

    for (int i = A; i <= B; i++) {
        for (int j = 0; j + i < len; j++) {
            // compute [j..j+i)
            int binary = 0;
            for (int k = j; k < j + i; k++) {
                binary *= 2;
                binary += (s[k] - '0');
            }
            // 2^i - 2 + binary(s[k..k+i])
            int idx = (1 << i) - 2 + binary;
            if (p[idx].freq == 0) {
                p[idx].str = string(s + j, s + j + i);
            }
            p[idx].freq++;
        }
    }

    sort(p, p+9000, compare);
    int i = 0;
    for (int n = 0; n < N && p[i].freq > 0; n++) {
        int cnt = 0;
        fout << p[i].freq << endl;
        do {
          cnt++;
          i++;
        } while (i < 9000 && p[i-1].freq == p[i].freq);
        for (int c = 1; c <= cnt; c++) {
          fout << p[i-cnt-1+c].str;
          if (c == cnt || c % 6 == 0) {
            fout << endl;
          } else {
              fout << " ";
          }
        }
    }
    return 0;
}
