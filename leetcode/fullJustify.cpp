#include "leetcode.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = words.size();
        vector<string> res;
        if (len == 1) {
            string s(L, ' ');
            copy(words[0], s, 0);
            res.push_back(s);
            return res;
        } else {
            int b = 0, count = 1;
            int acc = words[0].length();
            for (int i = 1; i < len; i++) {
                if (acc + words[i].length() + 1 <= L) {
                    count++;
                    acc += (words[i].length() + 1);
                } else {
                    int remain = L - acc + count - 1;
                    string s(L, ' ');
                    int idx = 0;
                    copy(words[b], s, idx);

                    if (count > 1) {
                        vector<int> space(count - 1, remain / (count-1));
                        for (int j = 0; j < remain % (count-1); j++)
                            space[j]++;
                        for (int j = 1; j < count; j++) {
                            idx += (words[b+j-1].length() + space[j-1]);
                            copy(words[b+j], s, idx);
                        }
                    }

                    res.push_back(s);

                    acc = words[i].length();
                    b += count;
                    count = 1;
                }
            }

            string s(L, ' ');
            int idx = 0;
            copy(words[b], s, idx);
            for (int i = 1; i < count; i++) {
                idx += (words[b+i-1].length() + 1);
                copy(words[b+i], s, idx);
            }
            res.push_back(s);

            return res;
        }
    }

    void copy(const string& src, string& des, int b) {
        for (int i = 0; i < src.length(); i++)
            des[b+i] = src[i];
    }
};

int main() {
  Solution s;

  //const char* data[] = {"a", "b", "c", "d", "e"};
  //const char* data[] = {"This", "is", "an", "example", "of", "text", "justification." };
  const char* data[] = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  vector<string> words(data, data + 19);
  vector<string> res = s.fullJustify(words, 30);
  for (int i=0; i < res.size(); i++)
    cout << res[i] << endl;
  return 0;
}
