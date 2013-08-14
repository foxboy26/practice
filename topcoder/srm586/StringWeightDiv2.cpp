class StringWeightDiv2 {
  public:
    int countMinimums(int L) {
      int res = 1;
      if (L <= 26) {
        for (int i = 0; i < L; i++)
          res = res * (26 - i) % 1000000009;
      } else {
        for (int i = 0; i < 26; i++)
          res = res * (26 - i) % 1000000009;
        
        int n = L - 1, k = 25;
        for (int i = 1; i <= k; i++)
          res = res * (n - (k - i)) % 1000000009;
        for (int i = 1; i <= k; i++)
          res = res / i % 1000000009;
      }

      return res;
    }
};
