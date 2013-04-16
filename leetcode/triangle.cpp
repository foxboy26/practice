class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = triangle.size();
        if (len == 0) return 0;
        
        int* res = new int[len];
        int* tmp = new int[len];
        
        res[0] = tmp[0] = triangle[0][0];
        
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0) tmp[j] = res[j];
                else if (j == i) tmp[j] = res[j-1];
                else tmp[j] = min(res[j], res[j-1]);
            }
            for (int j = 0; j <= i; j++)
                res[j] = tmp[j] + triangle[i][j];
        }
        
        int min_res = INT_MAX;
        for (int i = 0; i < len; i++)
            min_res = min(min_res, res[i]);
        
        return min_res;
    }
};
