#include <iostream>
using namespace std;

bool isNumber(const char* str) {
  bool firstZero = true;
  bool canSign = true;
  bool canDot = true;
  bool haveNum = false;
  bool numBegin = false;

  if (str == NULL || *str == '\0') return false;

  while (*str != '\0') {
    char c = *(str++);

    if (c == '+' || c == '-') {
      if (!canSign) return false;
      canSign = false;
      numBegin = true;
      continue;
    }

    if (c == '.') {
      if (!canDot) return false;
      canDot = false;
      numBegin = true;
      continue;
    }

    if (c >= '1' &&  c <= '9') {
      numBegin = true;
      haveNum = true;
      canSign = false;
    } else {
      return false;
    }
  }

  return haveNum;
}

int main() {
  const char* str = "+0233";

  cout << isNumber(str) << endl;

  return 0;
}
