/*
ID: foxboy21
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

char digit[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 

string toBase(int num, int base)
{
  string str = "";

  while (num > 0)
  {
    str = digit[num % base] + str;
    num /= base;
  }
  return str;
}

bool isPalindromic(string str)
{
  int len = str.length();
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - i - 1])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");

  int N, S;

  fin >> N >> S;

  int i = S + 1, n = 0;
  while (n < N)
  {
    int count = 0;
    for (int b = 2; b <= 10; b++)
    {
      if (isPalindromic(toBase(i, b)))
      {
        count++;
        if (count >= 2)
        {
          fout << i << "\n";
          n++;
          break;
        }
      }
    }
    i++;
  }
  
  fin.close();
  fout.close();

  return 0;
}
