#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string path)
{
  stack<string> s;

  int len = path.length();
  int start = 1;
  if (path[len-1] != '/') path.append("/");
  len = path.length();
  for (int i = 0; i < len; i++)
  {
    if (path[i] == '/')
    {
      if (i > start)
      {
        string part = path.substr(start, i - start);
        if (part == "..")
        {
          if (!s.empty())
            s.pop();
        }
        else if (part == ".") {}
        else
          s.push(part);
      }
      start = i + 1;
    }
  }

  string res = "";
  if (s.empty())
    res = "/";
  else
  {
    while (!s.empty())
    {
      res = "/" + s.top() + res;
      s.pop();
    }
  }

  return res;
}

int main()
{
  string test;
  cin >> test;
  cout << simplifyPath(test) << endl;

  return 0;
}
