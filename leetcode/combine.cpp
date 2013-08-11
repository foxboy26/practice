#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->n = n;
        this->k = k;
        vector<int> tmp;
        combineHelp(1, 0, tmp);
        return res;
    }
    
    void combineHelp(int curN, int curK, vector<int>& tmp) {
        if (curK == this->k) {
          for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
          cout << endl;
            res.push_back(tmp);
            return;
        }
        
        for (int j = curN; j <= this->n; j++) {
            tmp.push_back(j);
            combineHelp(j + 1, curK + 1, tmp);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int> > res;
    int n;
    int k;
};

int main()
{
  Solution s;
  vector<vector<int> > res = s.combine(4, 2);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
