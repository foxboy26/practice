class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2) return n;
        
        int a = 1, b = 1;
        for (int i = 1; i < n; i++) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b; 
    }
};