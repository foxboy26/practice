class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxDis = 0;
        int cur = 0;
        int step = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxDis) {
                maxDis = cur;
                step++;
            }
            
            cur = max(cur, i + A[i]);
        }
        
        return step;
    }
};