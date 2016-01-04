#include <iostream>
#include <vector>
using namespace std;

int minAbs(vector<int> &a, vector<int> &b) {
  int i = 0, j = 0;
  int minVal = INT_MAX;
  int aLen = a.size(), bLen = b.size();

  while (i < aLen && j < bLen) {
    int diff = abs(a[i] - b[j]);
    minVal = min(minVal, diff);
    if (a[i] > b[j]) j++;
    else i++;
  }

  return minVal;
}

int main()
{
  vector<int> a, b;
  int sizeA, sizeB;
  cin >> sizeA >> sizeB;
  int ele;
  for (int i = 0; i < sizeA; i++) {
    cin >> ele;
    a.push_back(ele);
  }
  for (int i = 0; i < sizeB; i++) {
    cin >> ele;
    b.push_back(ele);
  }

  cout << minAbs(a, b) << endl;

  return 0;
}
