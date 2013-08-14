#include <iostream>
#include <stack>
using namespace std;

int main()
{
  char str[256];
  int n;
  bool valid;

  cin >> n;
  cin.ignore(1, '\n');

  for (int i = 0; i < n; i++)
  {
    cin.getline(str, 256);
    valid = true;
    stack<char> s;
    for (int j = 0; str[j]; j++)
    {
      if (str[j] == '(' || str[j] == '[')
      {
        s.push(str[j]);
      }
      else if (str[j] == ')')
      {
        if (!s.empty() && s.top() == '(')
        {
          s.pop();
        }
        else
        {
          valid = false;
          break;
        }
      }
      else if (str[j] == ']')
      {
        if (!s.empty() && s.top() == '[')
        {
          s.pop();
        }
        else
        {
          valid = false;
          break;
        }
      }
    }

    if (!s.empty()) valid = false;
    
    cout << ((valid)? "Yes" : "No") << endl;
  }

  return 0;
}
