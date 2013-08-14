#include <string>

using namespace std;

class ColorfulBricks
{
public:
  int countLayouts(string bricks)
  {
    bool v[26];
    for (int i = 0; i < 26; i++) v[i] = false;

    int count = 0;
    for (int i = 0; i < bricks.length(); i++)
    {
      if (!v[bricks[i] - 'A']) 
      {
        count++;
        v[bricks[i] - 'A'] = true;
      }
    }

    if (count == 1) return 1;
    else if (count == 2) return 2;
    else return 0;
  }
};
