#include "leetcode.h"
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> dictList;
        dictList.push_back(start);
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (*it != start && *it != end)
                dictList.push_back(*it);
        }
        dictList.push_back(end);

        int n = dictList.size();
        vector<bool> v(n, false);
        vector<int> dis(n, 0);

        cout << n << endl;

        queue<int> q;
        q.push(0);
        v[0] = true;
        dis[0] = 1;
        while (!q.empty()) {
            int t = q.front();
            q.pop();

            if (t == n-1) break;

            for (int i = 0; i < n; i++) {
                if (!v[i] && canTransform(dictList[t], dictList[i])) {
                    v[i] = true;
                    cout << "hah" << endl;
                    dis[i] = dis[t] + 1;
                    q.push(i);
                }
            }
        }

        return dis[n-1];
     }

     bool canTransform(const string& a, const string& b) {
         int count = 0;
         for (int i = 0; i < a.length(); i++) {
             if (a[i] != b[i]) count++;
         }
         return (count == 1);
     }
};

int main() {
    Solution s;
    string start = "a";
    string end = "c";
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("b");
    dict.insert("c");

    cout << s.ladderLength(start, end, dict) << endl;

    return 0;
}
