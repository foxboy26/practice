int numTrees(int n) {
  if (n < 3) return n;

  int* res = new int[n + 1];

  for (int i = 0; i <= n; i++)
    res[i] = 0;

  res[0] = 1;
  res[1] = 1;
  res[2] = 2;

  for (int i = 3; i <= n; i++)
    for (int j = 0; j < i; j++)
      res[i] += (res[j] * res[i - j - 1]);    

  int result = res[n];

  delete [] res;        

  return result;
}
