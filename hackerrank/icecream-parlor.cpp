#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct num {
  int n;
  int idx;
};

bool mySort(const num& a, const num& b)
{
  return a.n < b.n;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, L, C;
  num a[10000];
  cin >> T;

  for (int t = 0; t < T; t++)
  {
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
      cin >> a[i].n;
      a[i].idx = i + 1;
    }
    sort(a, a+C, mySort);

   int i = 0, j = C - 1;
   while (i < j)
   {
     if (a[i].n + a[j].n > L) j--;
     else if (a[i].n + a[j].n < L) i++;
     else break;
   }
   
   if (a[i].idx < a[j].idx)
     cout << a[i].idx << " " << a[j].idx << endl;
   else
     cout << a[j].idx << " " << a[i].idx << endl;
  }
  return 0;
}
