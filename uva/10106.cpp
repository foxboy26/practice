#include <iostream>
#include <cstring>
using namespace std;

const int MAX_DIGIT = 600;

struct Number
{
  char num[MAX_DIGIT];
  int decimal_place;
  int digits;
};

Number multi(const Number& lhs, const Number& rhs);
void print(const Number& num);

Number multi(const Number& lhs, const Number& rhs)
{
  Number res;

  if ((lhs.digits == 1 && lhs.num[0] == 0) || (rhs.digits == 1 && rhs.num[0] == 0))
  {
    res.digits = 1;
    res.num[0] = 0;
    return res;
  }

  res.digits = lhs.digits + rhs.digits;
  res.decimal_place = lhs.decimal_place + rhs.decimal_place;

  for (int i = 0; i < res.digits; i++) res.num[i] = 0;

  int r, pos;
  for (int i = rhs.digits - 1; i >= 0; i--)
  {
    r = 0;
    pos = i + lhs.digits;
    for (int j = lhs.digits - 1; j >= 0; j--)
    {
      res.num[pos] += (rhs.num[i] * lhs.num[j] + r);
      r = res.num[pos] / 10;
      res.num[pos] = res.num[pos] % 10;
      pos--;
    }
    res.num[pos] += r;
  }
  
  for (int i = res.digits - 1; i >= res.decimal_place; i--)
  {
    if (res.num[i] == 0)
    {
      res.digits--;
    }
    else
    {
      break;
    }
  }

  int leading_zeros = 0;
  for (int i = 0; i < res.decimal_place; i++)
  {
    if (res.num[i] == 0)
    {
      leading_zeros++;
    }
    else
    {
      break;
    }
  }

  res.decimal_place -= leading_zeros;
  res.digits -= leading_zeros;
  
  if (leading_zeros > 0)
  {
    for (int i = 0; i < res.digits; i++)
    {
      res.num[i] = res.num[i + leading_zeros];
    }
  }

  return res;
}

void print(const Number& num)
{
  for(int i = 0; i < num.digits; i++)
  {
    if (i == num.decimal_place)
      cout << ".";
    cout << (int) num.num[i]; 
  }
}

int main()
{
  char a[250], b[250];
  Number l, r;

  while (cin >> a >> b)
  {
    for (int i = 0; a[i]; i++)
    {
      l.num[i] = a[i] - '0';
    }
    l.digits = strlen(a);
    l.decimal_place = strlen(a);

    for (int i = 0; b[i]; i++)
    {
      r.num[i] = b[i] - '0';
    }
    r.digits = strlen(b);
    r.decimal_place = strlen(b);

    print(multi(l, r)); cout << endl;
  }

  return 0;
}
