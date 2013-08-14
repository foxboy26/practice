#include <iostream>
#include <string>
using namespace std;

string add(string num1, string num2)
{
  int res[500];
  for (int i = 0; i < 250; i++) res[i] = 0;

  int pos = 499;
  int r = 0;
  for (int i = num1.length() - 1; i >= 0; i--)
  {
    pos = 500 - (num1.length() - i);
    r = 0;
    for (int j = num2.length(); j >= 0; j--)
    {
      k = num1[i] * num2[j] % 10;
      res[pos--] += (k + r)
      r = num1[i] * num2[j] / 10;
    }
  }
}

void print(int num)
{
  int b = 0;
  for (int i = 0; i < num
}

int main()
{
  string num1, num2;

  
  //while (cin >> num1)
  //{
  //  cin >> num2;

  //  cout << multi(num1, num2) << endl;
  //}
}
