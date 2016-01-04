#include "leetcode.h"
using namespace std;

string countAndSay(int n) {
  stringstream ss;
  string prev;

  if (n == 0) return "";

  prev = "1";
  for (int i = 1; i < n; i++) {
    char last = prev[0];
    int count = 1;
    for (int j = 1; j < prev.length(); j++) {
      if (prev[j] == last) {
        count++;
      } else {
        ss << count << last;
        last = prev[j];
        count = 1;
      }
    }
    ss << count << last;

    prev = ss.str();
    ss.str("");
  }

  return prev;
}

int main() {
  int n;
  cin >> n;
  cout << countAndSay(n) << endl;
}
