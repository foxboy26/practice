class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n >= 0)
            return pow_(x, n);
        else
            return 1.0 / pow_(x, -n); 
    }
private:
    double pow_(double x, int n) {
        if (n == 0)
            return 1.0;
            
        double res = pow_(x, n/2);
        
        return (n % 2 == 0)? res * res : res * res * x;
    }
};