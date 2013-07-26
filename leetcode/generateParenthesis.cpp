vector<string> generateParenthesis(int n) {
  vector<string> res;
  if (n == 0) {
    res.push_back("");
  }

  for (int i = 0; i < n; i++) {
    vector<string> left = generateParenthesis(i);
    vector<string> right = generateParenthesis(n - i -1);
    for (int j = 0; j < left.size(); j++) {
      for (int k = 0; k < right.size(); k++) {
        string str = "(" + left[j] + ")" + right[k];

        res.push_back(str);
      }
    }
  }

  return res;
}
