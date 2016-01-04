class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m*n;
        while (l < h) {
            int mid = l + (h-l)/2;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            }

            if (matrix[mid / n][mid % n] > target) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
