#include "leetcode.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->s = s;
        d[0] = 0; d[4] = s.length();
        
        search(0, 0);
        return res;
    }
    
    void search(int start, int n) {
        if (start + (4-n) * 3 < s.length())
            return;
        
        if (n == 4) {
            string ip(s.length() + 3, '.');
            for (int i = 0; i < 4; i++)
                for (int j = d[i]; j < d[i+1]; j++)
                    ip[j+i] = s[j];
            res.push_back(ip);
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            if (start+i <= s.length() && isValid(s.substr(start, i))) {
                d[n+1] = start+i;
                search(start+i, n+1);                
            }
        }
    }
    
    bool isValid(string str) {
        int field = str[0] - '0';
        for (int i = 1; i < str.length(); i++) {
            field *= 10;
            field += (str[i] - '0');
        }
        
        return (field >= 0 && field <= 255);
    }
    
    string s;
    vector<string> res;
    int d[5];
};

int main() {
  Solution s;
  //vector<string> res = s.restoreIpAddresses("25525511135");
  vector<string> res = s.restoreIpAddresses("1111");

  printVector(res);

  return 0;
}
