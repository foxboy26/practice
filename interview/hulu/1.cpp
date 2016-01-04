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

bool isPalindrome(const string& str) {
  int len = str.length();
  for (int i = 0; i <= len/2; i++) {
    if (str[i] != str[len-i-1]) {
      return false;
    }
  }
  return true;
}

int main()
{
  int T;
  cin >> T;
  string str;
  bool res = false;
  for (int t = 1; t <= T; t++) {
    cin >> str;
    res = isPalindrome(str);
    cout << "Case #" << t << endl;
    if (res) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
