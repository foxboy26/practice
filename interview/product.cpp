#include <iostream>
using namespace std;

void productNoDivided(int num[], int size)
{
  if (size < 2) return;

  int* tmp = new int[size];
  tmp[0] = 1;
  for (int i = 1; i < size; i++)
    tmp[i] = tmp[i-1] * num[i-1];

  for (int i = 0; i < 5; i++)
    cout << tmp[i] << " ";
  cout << endl;

  int p = 1;
  for (int i = size - 1; i >= 0; i--) {
    tmp[i] = tmp[i] * p;
    p *= num[i];
  }

  for (int i = 0; i < size; i++)
    num[i] = tmp[i];

  delete [] tmp;
}

int main()
{
  int num[1] = {2};

  productNoDivided(num, 1);

  for (int i = 0; i < 1; i++)
    cout << num[i] << " ";
  cout << endl;

  return 0;
}
