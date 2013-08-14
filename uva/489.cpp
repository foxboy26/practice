#include <iostream>
#include <string>
using namespace std;

int main()
{
  int C;

  bool c[26];
  bool g[26];
  int life, hit, all, idx;
  string puzzle, guess;

  while (true)
  {
    cin >> C;
    if (C == -1)
    {
      break;
    }

    cin >> puzzle >> guess;

    for (int i = 0; i < 26; i++)
    {
      c[i] = g[i] = false;
    }

    all = 0;
    for (int i = 0; i < puzzle.length(); i++)
    {
      idx = puzzle[i] - 'a';
      if (c[idx] == false)
      {
        c[idx] = true;
        all++;
      }
    }

    life = 7;
    hit = 0;
    for (int i = 0; i < guess.length(); i++)
    {
      idx = guess[i] - 'a';
      if (g[idx] == false)
      {
        g[idx] = true;
        if (c[idx])
        {
          hit++;
        }
        else
        {
          life--;  
        }
      }

      if (hit == all || life == 0)
      {
        break;
      }
    }

    cout << "Round " << C << "\n";
    if (life > 0)
    {
      if (hit == all)
      {
        cout << "You win.\n";
      }
      else
      {
        cout << "You chickened out.\n";
      }

    }
    else
    {
      cout << "You lose.\n";
    }
  }

  return 0;
}
