class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s);
        int res = 0;
        int i = len-1;
        while (s[i] == ' ' && i >= 0) i--;
        for (i; i>= 0; i--) {
            if (s[i] != ' ') res++;
            else break;
        }
        
        return res;
    }
};