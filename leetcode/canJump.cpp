bool canJump(int A[], int n) {
  int* a = new int[n];
  bool can = true;

  a[0] = 0;
  for (int i = 1; i < n; i++)
  {
    a[i] = max(a[i-1], A[i-1]) - 1;
    if (a[i] < 0)
    {
      can = false;
      break;
    }
  }

  delete [] a;

  return can;
}
