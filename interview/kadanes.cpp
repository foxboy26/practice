#include <iostream>
using namespace std;

int kadanes(int a[], int len)
{
  if (len == 0) return -1;

  int currentMaxSum;
  int maxSum;
  int begin = 0;
  int tmpBegin = 0;
  int end = 0;

  currentMaxSum = maxSum = a[0];

  for (int i = 0; i < len; i++) {
    if (currentMaxSum < 0) {
      tmpBegin = i;
      currentMaxSum = a[i];
    } else {
      currentMaxSum += a[i];
    }

    if (currentMaxSum > maxSum) {
      begin = tmpBegin;
      end = i;
      maxSum = currentMaxSum;
    }
  }
    cout << begin << " " << end << endl;

    return maxSum;
}


int main()
{
    int a[7] = {-2, 3, -1, 7, 13, -22, 4};

    cout << kadanes(a, 7) << endl;

    return 0;
}
