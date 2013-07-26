vector<int> twoSum(vector<int> &numbers, int target) {
  vector<pair<int, int>> 
    sort(numbers.begin(), numbers.end());

  int i = 0;
  int j = numbers.size();
  vector<int> res;
  while (i < j)
  {
    if (numbers[i] + numbers[j] < target)
      i++;
    else if (numbers[i] + numbers[j] > target)
      j--;
    else
    {
      res.push_back(i);
      res.push_back(j);
      break;
    }
  }

  return res;
}
