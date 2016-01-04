#include <iostream>
using namespace std;

int iter = 0;
int a = 0;
int b = 1;

int next() {
    if (iter++ == 0) return 0;
    else if (iter++ == 1) {
        a = b;
        b = 1;
        return b;
    }
    else {
        int res = a + b;
        a = b;
        b = res;
        iter++;
        return b;
    }
}

int main()
{
    for (int i = 0; i < 10; i++) cout << next() << endl;

    return 0;
}

