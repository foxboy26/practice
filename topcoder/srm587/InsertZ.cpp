#include <string>
using namespace std;

class InsertZ {
  public:
    string canTransform(string init, string goal) {
      int j = 0;
      for (int i = 0; i < goal.length(); i++) {
        if (goal[i] == init[j])
          j++;
        else if (goal[i] == 'z')
          continue;
        else
          return "No";
      }

      return (j == init.length())? "Yes" : "No";
    }
};
