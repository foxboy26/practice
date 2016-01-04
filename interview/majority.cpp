#include <iostream>
#include <vector>
using namespace std;

int findMajority(vector<int>& a) {
    int n = a.size();
    if (n == 0) return -1;

    int majorityIndex = 0, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[majorityIndex]) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == a[majorityIndex]) count++;
    }

    if (count > n / 2)
        return majorityIndex;
    else
        return -1;
}

int main() {
    vector<int> a;
    a.push_back(2);
    a.push_back(6);
    a.push_back(6);
    a.push_back(5);
    a.push_back(6);
    a.push_back(6);
    a.push_back(5);
    a.push_back(6);

    cout << findMajority(a) << endl;

    return 0;
}
