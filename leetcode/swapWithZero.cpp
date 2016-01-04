#include "leetcode.h"

#define N 5

void swapWithZero(int src[], int tgt[], int n) {
    int mapping[N];
    for (int i = 0; i < n; i++) {
        mapping[src[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (src[i] != tgt[i]/* && tgt[i] != 0*/) {
            int zeroIndex = mapping[0];
            int tgtIndex = mapping[tgt[i]];
            swap(src[i], src[zeroIndex]);
            swap(mapping[src[i]], mapping[src[zeroIndex]]);
            swap(src[i], src[tgtIndex]);
            swap(mapping[src[i]], mapping[src[tgtIndex]]);
        }
    }
}

int main() {
    int src[N] = {2, 1, 3, 0, 4};
    int tgt[N] = {2, 3, 1, 4, 0};

    swapWithZero(src, tgt, N);

    for (int i = 0; i < N; i++)
        cout << src[i] << " ";
    cout << endl;

    return 0;
}
