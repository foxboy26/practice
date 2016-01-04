#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

int getRandom(int n, int k[], int kLen) {
    int res = rand() % (n - kLen);

    int x = -1;
    for (int i = 0; i < kLen; i++) {
        if (res >= (k[i] - i)) x = i;
        else break;
    }

    return res + x + 1;
}

int getWeightedRandom(int weight[], int n) {
    for (int i = 1; i < n; i++) {
        weight[i] += weight[i-1];
    }

    int N = weight[n-1];
    int res =rand() % N;

    int x = 0;
    for (int i = 0; i < n; i++) {
        if (res <= weight[i]) x = i;
        else break;
    }

    return x;
}

int main()
{
    srand(time(NULL));
    int k[] = {1, 2, 3};
    int n = 8;
    map<int, int> count;
    count[0] = 0;
    count[4] = 0;
    count[5] = 0;
    count[6] = 0;
    count[7] = 0;

    for (int i = 0; i < 10000; i++) {
        count[getRandom(n, k, 3)]++;
    }

    for (auto it = count.begin(); it != count.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
