#include <iostream>
using namespace std;

int fib3(int n) {
    int a[3] = {1, 1, 2};
    if (n < 3) return a[n];
    else {
        int res = a[2];
        for (int i = 3; i <= n; i++) {
            res = a[0] + a[1] + a[2];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = res;
        }
        return res;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cout << fib3(i) << endl;
    }

    return 0;
}
