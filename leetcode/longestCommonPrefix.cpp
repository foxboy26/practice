#include "leetcode.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        int len = INT_MAX;
        for (int i = 0; i < strs.size(); i++) len = min(len, (int) strs[i].length());
        cout << len << endl;

        bool found = true;
        int i;
        for (i = 0; i < len && found; i++) {
          cout << found << endl;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[j-1][i]) {
                    found = false;
                    break;
                }
            }
        }
        cout << i << endl;
        cout << strs[0] << endl;
        cout << strs[0].substr(1) << endl;
        cout << strs[0].substr(0) << endl;
        if (!found) i--;
        return strs[0].substr(0, i);
    }
};

int main() {
  Solution s;
  const char* data[] = {"b", "c"};
  vector<string> strs(data, data + 2);
  cout << s.longestCommonPrefix(strs) << endl;

  return 0;
}
