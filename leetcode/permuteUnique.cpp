#include "leetcode.h"
using namespace std;

class Solution {
  public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
      vector<vector<int> > res;
      vector<int> path;
      vector<bool> used(num.size(), false);

      sort(num.begin(), num.end());

      permuteUniqueHelp(num, path, res, used);

      return res;
    }

    void permuteUniqueHelp(vector<int> &num, vector<int>& path, vector<vector<int> >& res, vector<bool>& used) {
      if (path.size() == num.size()) {
        printVector(path);
      } else {
          for (int i = 0; i < num.size(); i++) {
              if (used[i] || (i != 0 && num[i] == num[i-1] && used[i-1])) continue;

              path.push_back(num[i]);
              printVector(path);
              used[i] = true;
              permuteUniqueHelp(num, path, res, used);
              path.pop_back();
              used[i] = false;
          }
      }
    }
};

int main() {
  int data[3] = {1, 2, 2};
  vector<int> num(data, data+3);

  Solution s;
  s.permuteUnique(num);
  return 0;
}
