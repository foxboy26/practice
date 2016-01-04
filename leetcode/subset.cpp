#include "leetcode.h"
void sub(vector<int> &s, int begin, vector<int> &path, 
        vector<vector<int> > &result) {
    if (begin == s.size()) {
    result.push_back(path);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
    }

    for (int i = begin; i < s.size(); ++i) {
        if (i != begin && s[i] == s[i - 1]) continue;

        path.push_back(s[i]);
        sub(s, i + 1, path, result);
        path.pop_back();
    }
}


vector<vector<int> > subsets(vector<int> &S) {     
    vector<int> path;
    vector<vector<int> > result;

    sort(S.begin(), S.end());
    sub(S, 0, path, result);
    return result;
}

int main()
{
    vector<int> a;
    for (int i = 1; i <= 3; i++)
        a.push_back(i);

    subsets(a);

    return 0;
}
