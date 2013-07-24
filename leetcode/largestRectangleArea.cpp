int largestRectangleArea(vector<int> &height) {
  stack<int> s;

  int n = height.size();
  int i = 0;
  int max_area = 0;
  int cur_area = 0;
  
  while (i < n)
  {
    if (s.empty() || height[s.top()] < height[i])
      s.push(i++);
    else
    {
      int t = s.top();
      s.pop();

      cur_area = height[t] * ((s.empty()? i : i - s.top() - 1));

      max_area = std::max(cur_area, max_area);
    }
  }

  while (!s.empty())
  {
    int t = s.top();
    s.pop();

    cur_area = height[t] * ((s.empty()? i : i - s.top() - 1));

    max_area = std::max(cur_area, max_area);
  }

  return max_area;
}
