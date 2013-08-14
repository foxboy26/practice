#include "codejam.h"

int main() {
  int T;
  int m, n;
  int mat[101][101] = {0};
  int cur[101][101] = {100};

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> mat[i][j];
    
    int maxH = INT_MIN;
    /* Cut row */
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        maxH = max(maxH, mat[i][j]);
      for (int j = 0; j < n; j++)
        cur[i][j] = maxH;
    }

    /* Cut column */
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        maxH = max(maxH, mat[j][i]);
      for (int j = 0; j < m; j++)
        cur[j][i] = min(cur[j][i], maxH);
    }

    /* Check if achieved desired pattern */
    bool canCut = true;
    for (int i = 0; i < m && canCut; i++)
      for (int j = 0; j < n && canCut; j++)
        if (mat[i][j] != cur[i][j])
          canCut = false;

    cout << "Case #" << t + 1 << ": " << ((canCut)? "YES" : "NO") << "\n";
  }

  return 0;
}
