int maxProfit(vector<int> &prices) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int len = prices.size();

  if (len < 2) return 0;

  int low = prices[0];
  int max_profit = 0;
  for (int i = 1; i < len; i++)
  {
      if (prices[i] < low)
          low = prices[i];
      else
          max_profit = max(prices[i] - low, max_profit);    
  }

  return max_profit;
}
