int maxProfit(vector<int> &prices) {
  int len = prices.size();
  if (len < 2) return 0;

  int sum = 0;
  for (int i = 1; i < len; i++)
  {
    int diff = prices[i] - prices[i-1];
    if (diff > 0) sum += diff;
  }

  return sum;
}
