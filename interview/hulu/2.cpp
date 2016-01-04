#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

#define MAX_N 10001

struct Letter {
  int count;
  char l;
};

bool letterCompare(const Letter& lhs, const Letter& rhs) {
  if (lhs.count < rhs.count) {
    return true;
  } else if (lhs.count == rhs.count) {
    if (lhs.l < rhs.l) {
      return false;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int main()
{
  int T;
  char str[MAX_N];
  cin >> T;
  // skip the first line
  cin.getline(str, MAX_N);

  Letter letter[26];
  for (int t = 1; t <= T; t++) {
    cin.getline (str, MAX_N);

    // init letter array
    for (int i = 0; i < 26; i++) {
      letter[i].count = 0;
      letter[i].l = i + 'a';
    }

    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] != ' ') {
        letter[str[i] - 'a'].count++;
      }
    }

    sort(letter, letter + 26, letterCompare);

    cout << "Case #" << t << "\n";
    for (int i = 25; i >= 0; i--) {
      if (letter[i].count > 0) {
        cout << letter[i].l << " " << letter[i].count << endl;
      } else {
        break;
      }
    }
  }

  return 0;
}
