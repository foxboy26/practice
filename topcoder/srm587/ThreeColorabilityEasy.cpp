#include <string>
#include <vector>
using namespace std;

#define MAX_N 51 * 51

class ThreeColorabilityEasy {
  public:
    string isColorable(vector <string> cells) {
      set<int> graph[MAX_N];
      bool isVisited[MAX_N] = {false};

      /* construct graph */
      h = cells.size();
      w = cells[0].length();
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (cells[i][j] == 'Z') {
            addEdge(i, j+1, i+1, j);
          } else {
            addEdge(i, j, i+1, j+1);
          }
        }
      }

      for (int i = 0; i <= h; i++)
        for (int j = 0; j < w; j++)
          addEdge(i, j, i, j+1);
      for (int i = 0; i < h; i++)
        for (int j = 0; j <= w; j++)
          addEdge(i, j, i+1, j);




  private:
      set<int> graph[MAX_N];

      addEdge(int i, int j, int m, int n) { graph[i
    
};
