#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(int A[], int n, int target);
int searchLeft(int A[], int n, int target);
int searchRight(int A[], int n, int target);

int main()
{
  int A[] = {1, 3, 8, 8, 8, 8, 8, 8};

  vector<int> res = searchRange(A, 8, 8);

  cout << res[0] << " " << res[1] << endl;

  return 0;
}

vector<int> searchRange(int A[], int n, int target) {
  vector<int> res(2);

  res[0] = searchLeft(A, n, target);
  res[1] = searchRight(A, n, target);

  return res;
}

int searchLeft(int A[], int n, int target) {
  int left = 0, right = n - 1;
  int mid;
  int res = -1;

  while (left <= right)
  {
    mid = (right - left) / 2 + left;
    
    if (A[mid] < target)
    {
      left = mid + 1;
    }
    else if (A[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      res = mid;
      right = mid - 1;
    }
  }

  return res;
}

int searchRight(int A[], int n, int target) {
  int left = 0, right = n - 1;
  int mid;
  int res = -1;

  while (left <= right)
  {
    cout << left << " " << right << endl;
    mid = (right - left) / 2 + left;
    
    if (A[mid] < target)
    {
      left = mid + 1;
    }
    else if (A[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      res = mid;
      left = mid + 1;
    }
  }

  cout << res << endl;

  return res;
}
