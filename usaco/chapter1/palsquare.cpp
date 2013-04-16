/*
ID: foxboy21
PROG: palsquare
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
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");

  int base;
  fin >> base;

  for (int i = 1; i <= 300; i++)
  {
    if (isPalindromic(toBase(i * i, base)))
    {
      fout << toBase(i, base) << " " << toBase(i * i, base) << endl;
    }
  }
  
  fin.close();
  fout.close();

  return 0;
}
