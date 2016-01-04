#include "leetcode.h"
using namespace std;

vector<vector<string> > res;
int N;

vector<vector<string> > solveNQueens(int n);
void solve(int k, vector<int>& row, vector<bool>& col, vector<bool>& dia, vector<bool>& dia2);
void genBoard(const vector<int>& row);

vector<vector<string> > solveNQueens(int n) {
  N = n;
  vector<int> row = vector<int> (n, -1);
  vector<bool> col(n, true);
  vector<bool> dia(n + n - 1, true);
  vector<bool> dia2(n + n - 1, true);
  solve(0, row, col, dia, dia2);

  return res;
}

void solve(int k, vector<int>& row, vector<bool>& col, vector<bool>& dia, vector<bool>& dia2) {
  if (k == N) {
    genBoard(row);
  } else {
    for (int i = 0; i < N; i++) {
      if (col[i] && dia[i + k] && dia2[i - k + N - 1]) {
        row[k] = i;

        col[i] = dia[i + k] = dia2[i - k + N - 1] = false;

        solve(k + 1, row, col, dia, dia2);

        col[i] = dia[i + k] = dia2[i - k + N - 1] = true;
      }
    }
  }
}

void genBoard(const vector<int>& row) {
  vector<string> board;
  for (int i = 0; i < N; i++)
    board.push_back(string(N, '.'));
  for (int i = 0; i < N; i++)
    board[i][row[i]] = 'Q';
  res.push_back(board);
}

int main() {
  int n;
  cin >> n;
  vector<vector<string> > res = solveNQueens(n);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j] << endl;
    }
    cout << endl;
  }

  return 0;
}
