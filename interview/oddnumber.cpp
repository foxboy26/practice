#include <iostream>
using namespace std;

int findOdd(int a[], int len)
{
    if (len == 0)  return -1;

    int res = a[0];
    for (int i = 1; i < len; i++)
    {
        res = res ^ a[i];
    }

    return res;
}

int main()
{
    int a[11] = {1,2,1,2,2,2,3,3,3, 4, 4};

    cout << findOdd(a, 11) << endl;
}
