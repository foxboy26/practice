#include <iostream>
#include <cmath>
using namespace std;

int sqrt(int x)
{
  if (x <= 1) return x;

  double x_k, x_k1 = 0;
  x_k = x_k1 = x;
  do
  {
    x_k = x_k1;
    x_k1 = (x_k + x / x_k) / 2;
  }
  while (fabs(x_k1 - x_k) >= 1);
  
  return x_k1;
}

int main()
{
  cout << sqrt(2147395599) << endl;
  cout << sqrt(99) << endl;

  return 0;
}
