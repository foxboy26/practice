#include <iostream>
#include <vector>
using namespace std;

vector<int> common(const vector<int> &a, const vector<int> &b) {
  int aLen = a.size();
  int bLen = b.size();

  vector<int> res;

  int i = 0, j = 0;

  while (i < aLen && j < bLen) {
    if (a[i] == b[j]) res.push_back(a[i]);

    if (a[i] > b[j]) j++;
    else i++;
  }

  return res;
}


int main()
{
  int data1[6] = {1, 3, 4, 5, 9, 10};
  int data2[4] = {2, 5, 8, 13};
  vector<int> a(data1, data1+6);
  vector<int> b(data2, data2+4);

  vector<int> res = common(a, b);

  for (int i= 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}
