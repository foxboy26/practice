int longestValidParentheses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len = s.length();
    
    int maxLen = 0;
    int last = -1;
    stack<int> st;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    maxLen = max(maxLen, i - last);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            } else {
                last = i;
            }
        }
    }
    
    return maxLen;
}