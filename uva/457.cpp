#include <iostream>
using namespace std;

int main()
{
  int C;
  
  cin >> C;

  int program[10];
  int dishes[40];
  char sym[4] = {' ', '.', 'x', 'W'};
  int old_dish, new_dish;

  bool writeNewline = false;
  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < 40; j++)
    {
      dishes[j] = ((j == 19)? 1 : 0);
    }

    for (int j = 0; j < 10; j++)
    {
      cin >> program[j];
    }

    if (writeNewline)
    {
      cout << "\n";
    }
    else
    {
      writeNewline = true;
    }
    
    for (int j = 0; j < 50; j++)
    {
      for (int k = 0; k < 40; k++)
      {
        cout << sym[dishes[k]];

        switch (k)
        {
        case 0:
          old_dish = dishes[0];
          dishes[0] = program[dishes[0] + dishes[1]]; break;
        case 39:
          dishes[39] = program[dishes[39] + old_dish]; break;
        default:
          new_dish = program[dishes[k] + dishes[k + 1] + old_dish];
          old_dish = dishes[k];
          dishes[k] = new_dish;
        }
      }
      cout << "\n";
    }
  }

  return 0;
}
