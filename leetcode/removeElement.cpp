class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[idx] = A[i];
                idx++;
            }
        }
        return idx;
    }
};