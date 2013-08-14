#include <iostream>
#include <string>
#include <list>
using namespace std;

list<int> brick[25];
int t[25];

void recover(int n)
{
  int p = brick[t[n]].back();
  for (; p != n; p = brick[t[n]].back())
  {
    brick[p].push_back(p);
    brick[t[n]].pop_back();
    t[p] = p;
  }
}

void move(int a, int b)
{
  brick[t[a]].pop_back();
  brick[t[b]].push_back(a);
  t[a] = t[b];
}

void pile(int a, int b)
{
  list<int> tmp;
  int p = brick[t[a]].back();

  for (; p != a; p = brick[t[a]].back())
  {
    tmp.push_back(p);
    brick[t[a]].pop_back();
    t[p] = t[b];
  }
  
  move(a, b);

  list<int>::reverse_iterator rp;
  for (rp = tmp.rbegin(); rp != tmp.rend(); rp++)
  {
    brick[t[b]].push_back(*rp);
  }
}

int main()
{
  int n;
  int a, b;
  string action, pos;

  cin >> n;
  
  for (int i = 0; i < n; i++)
  {
    brick[i].push_back(i);
    t[i] = i;
  }

  while (cin >> action)
  {
    if (action == "quit") break;

    cin >> a >> pos >> b;

    if (a < 0 || a > n - 1 || b < 0 || b > n - 1 || a == b || t[a] == t[b]) continue;

    if (action == "move")
    {
      recover(a);
      if (pos == "onto") recover(b);
      move(a, b);
    }
    else if (action == "pile")
    {
      if (pos == "onto") recover(b);
      pile(a, b);
    }
  }

  list<int>::iterator p;
  for (int i = 0; i < n; i++)
  {
    cout << i << ":";
    for (p = brick[i].begin(); p != brick[i].end(); p++)
      cout << " " << *p;
    cout << endl;
  }

  return 0;
}
