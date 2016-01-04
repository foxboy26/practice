#include <iostream>
#include <vector>
using namespace std;

vector<int> dividedBySqrtN(vector<int> arr) {
    vector<int> res;
    int N = arr.size();
    if (N < 1) return res;

    int n = sqrt(N);

    int minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            minVal = min(minVal, arr[i*n + j]);
        }
        res.push_back(minVal);
    }

    minVal = INT_MAX;
    for (int i = n*n; i < N; i++) {
        minVal = min(arr[i], minVal);
    }
    res.push_back(minVal);

    return res;
}

int query(vector<int> arr, int left, int right) {
    vector<int> preprocess = dividedBySqrtN(arr);
    int n = sqrt(arr.size());
    int start = left / n;
    int end = right / n;
    int res = INT_MAX;
    for (int i = start+1; i < end; i++)
        res = res(preprocess[i], res);

    int firstMin = INT_MAX;
    for (int i = left; i < start * n; i++)
        firstMin = min(firstMin, arr[i];

    int lastMin = INT_MAX;
    for (int i = end * n; i <= right; i++)
        lastMin = min(lastMin, arr[i];

    return min(res, min(firstMin, lastMin));
}

vector<int> segmentTree(vector<int> input) {
    int height = (int) ceil(log2(input.size()));
    int max_size = 1 << (height + 1) - 1;
    vector<int> tree(max_size, INT_MAX);
    segmentTreeHelp(input, tree, 0, input.size());

    return tree;
}

void segmentTreeHelp(vector<int> input, vector<int>& tree, int b, int e) {
    if (b == e) {
        tree[idx] = input[b];
        return tree[idx];
    } else {
        tree[idx] = min(segmentTreeHelp(input, tree, b, (b+e)/2, 2 * idx),
                        segmentTreeHelp(input, tree, (b+e)/2 + 1, e, 2 * idx + 1);
        return tree[idx];
    }
}

int querySegmentTree(vector<int> input, int left, int right) {
    vector<int> tree = segmentTree(input);

    return querySegmentTreeHelp(tree, 0, input.size() - 1, left, right, 0);
}

int querySegmentTreeHelp(vector<int> tree, int ss, int se, int left, int right, int idx) {
    if (se < left || ss > left) return INT_MAX;

    if (ss >= left && se <= right) return tree[idx];
    else return min(querySegmentTreeHelp(tree, ss, (ss+se)/2, left, right, 2 * idx),
                    querySegmentTreeHelp(tree, (ss+se)/2 + 1, se, left, right, 2 * idx + 1),
}

void sparseTable(int input[], int st[][]) {
    for (int i = 0; i < n; i++) {
        st[0][i] = i;
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            if (st[i][j-1] < st[i+ (1 << j) -1][j-1];
}

int main()
{

    return 0;
}
