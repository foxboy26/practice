#include "leetcode.h"
using namespace std;

class MinStack {
    public:
        void push(int val) {
            if (minStack.empty() || val < minStack.top())
                minStack.push(val);
            s.push(val);
        }

        void pop() {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }

        int top() {
            return s.top();
        }

        int min() {
            return minStack.top();
        }
    private:
        stack<int> s;
        stack<int> minStack;
};


int main() {
    MinStack ms;
    ms.push(7);
    cout << ms.min();
    ms.push(5);
    cout << ms.min();
    ms.push(9);
    cout << ms.min();
    ms.push(4);
    cout << ms.min();
    ms.push(2);
    cout << ms.min();
    ms.push(1);
    cout << ms.min();
    ms.pop();
    ms.pop();
    cout << ms.min();
    return 0;
}
