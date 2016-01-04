#include "leetcode.h"
using namespace std;

template <typename T>
class Queue {
    stack<T> s1;
    stack<T> s2;
    void move() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    void push(T elem) {
        s1.push(elem);
    }

    void pop() {
        move();
        s2.pop();
    }

    T top() {
        move();
        return s2.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    Queue<int> q;

    for (int i = 0; i < 5; i++)
        q.push(i);
    
    for (int i = 0; i < 5; i++) {
        cout << q.top() << endl;
        q.pop();
    }

    return 0;
}
