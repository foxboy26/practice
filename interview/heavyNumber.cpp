#include <iostream>
using namespace std;

bool isHeavy(int num);

int main()
{
  int a, b;
  cin >> a >> b;

  int count = 0;
  for (int i = a; i <= b; i++)
  {
    if (isHeavy(i))
    {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

bool isHeavy(int num)
{
  int sum = 0;
  int digits = 0;
  while (num > 0)
  {
    digits++;
    sum += (num % 10);
    num /= 10;
  }

  return (sum > (digits * 7));
}
