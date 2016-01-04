#include "leetcode.h"

int maxProductSubarray(const vector<int>& num) {
    int maxElement = INT_MIN;
    int curMax = 1;
    int maxSofar = 1;
    int minSofar = 1;
    int negatives = 0;
    bool pairExists = false;

    for (int i = 0; i < num.size(); i++) {
        if (num[i] > 0) {
            maxSofar = maxSofar * num[i];
            minSofar = min(minSofar * num[i], 1);
        } else if (num[i] < 0) {
            negatives++;
            int tmp = maxSofar;
            maxSofar = max(minSofar * num[i], 1);
            minSofar = tmp * num[i];
        } else {
            if (negatives > 1) pairExists = true;
            negatives = 0;
            maxSofar = minSofar = 1;
        }
        curMax = max(curMax, maxSofar);
        maxElement = max(maxElement, num[i]);
    }

    if (maxElement > 0 || pairExists) return curMax;
    else return maxElement;
}

int main()
{
    vector<int> num({-1, -1, 0, -1, 0});

    cout << maxProductSubarray(num) << endl;

    return 0;
}
