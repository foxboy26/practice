#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n, len, col, row, extra, pos;
  string str[100];

  while (cin >> n)
  {
    len = 0;
    for (int i = 0; i < 60; i++) cout << "-"; cout << endl;

    for (int i = 0; i < n; i++)
    {
      cin >> str[i];
      if (str[i].length() > len)
      {
        len = str[i].length();
      }
    }

    sort(str, str + n);
    
    col = 62 / (len + 2);
    row = n / col;
    extra = n % col;
    
    cout << left;
    for (int i = 0; i < row; i++)
    {
      pos = i;
      for (int j = 0; j < col - 1; j++)
      {
        cout << setw(len + 2) << str[pos];
        if (j < extra)
        {
          pos += (row + 1);
        }
        else
        {
          pos += row;
        }
      }
      cout << setw(len) << str[pos] << endl;
    }

    if (extra > 0)
    {
      for (int i = 0; i < extra - 1; i++)
      {
        cout << setw(len + 2) << str[i * (row + 1) + row];
      }
      cout << str[(extra - 1) * (row + 1) + row] << endl;
    }
  }
  return 0;
}
