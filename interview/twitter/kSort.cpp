#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kSortHelp(vector<int>& arr, int k) {
    priority_queue<int> pq;
    vector<int> sorted;
    int n = arr.size();
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < n; i++) {
        sorted.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty()) {
        sorted.push_back(pq.top());
        pq.pop();
    }

    return sorted;
}

bool checkSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}

vector<int> kSort(vector<int>& arr) {
    vector<int> res;
    int n = arr.size();
    for (int k = 1; k < n; k <<= 1) {
        res = kSortHelp(arr, k);
        if (checkSorted(res))
            return res;
    }

    return kSortHelp(arr, n);
}

int main()
{
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(rand() % 10);
    }

    vector<int> res = kSort(arr);
    /* vector<int> res = kSortHelp(arr, 1); */

    for (int i= 0; i < arr.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
