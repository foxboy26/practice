class Solution {
  public:
    vector<vector<int> > permute(vector<int> &num) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      vector<vector<int> > res;
      permuteHelp(num, 0, res);

      return res;
    }

    void permuteHelp(vector<int> &num, int n, vector<vector<int> >& res) {
      if (n == num.size()) {
        res.push_back(num);
      } else {
        for (int i = n; i < num.size(); i++) {
          swap(num[n], num[i]);
          permuteHelp(num, n+1, res);
          swap(num[n], num[i]);
        }
      }
    }
};
