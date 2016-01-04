#include <iostream>
using namespace std;

/* uint32_t swapBits(uint32_t n, int i, int j) { */
/*     uint32_t ith = ((n >> i) & 1); */
/*     uint32_t jth = ((n >> j) & 1); */

/*     if (ith ^ jth) { */
/*         n ^= ((1 << i) ^ (1 << j)); */
/*     } */

/*     return n; */
/* } */

void swapBits(char& c, int i, int j) {
    uint32_t ith = ((c >> i) & 1);
    uint32_t jth = ((c >> j) & 1);

    if (ith ^ jth)
        c ^= ((1 << i) ^ (1 << j));
}

void reverse(char& c) {
    int n = sizeof(c) * 8;
    int i = 0, j = n - 1;
    while (i < j) {
        swapBits(c, i, j);
        i++;
        j--;
    }
}

void flipImage(char image[], int m, int n) {
    for (int i = 0; i < m * n; i++) reverse(image[i]);
    for (int i = 0; i < m; i++) {
        int begin = i * n, end = (i + 1) * n - 1;
        while (begin <= end) {
            swap(image[begin], image[end]);
            begin++;
            end--;
        }
    }
}

void printChar(char c) {
    string s(8, '0');
    int i = 0;

    for (int i = 0; i < 8; i++) {
        s[7 - i] = ((c >> i) & 1) + '0';
    }
    cout << s;
}

int main()
{
    char image[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 6; j++) {
            printChar(image[i * 6 + j]);
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    flipImage(image, 1, 6);
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 6; j++) {
            printChar(image[i * 1 + j]);
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
