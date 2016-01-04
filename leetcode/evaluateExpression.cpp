#include "leetcode.h"
using namespace std;

int evalOp(char op, int a, int b) {
    int res;
    switch(op) {
        case '+':
            res = a + b; break;
        case '-':
            res = b - a; break;
        case '*':
            res = a * b; break;
        case '/':
            res = b / a; break;
        default:
            cerr << "error!" << endl;
    }

    return res;
}

bool hasPrecedence(char lhs, char rhs) {
    return ((lhs == '+' || lhs == '-') && (rhs == '*' || rhs == '/'));
}

int evaluate(string expr) {
    stack<char> ops;
    stack<int> vals;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            vals.push(expr[i] - '0');
        } else {
            while (!ops.empty() && hasPrecedence(expr[i], ops.top())) {
                char op = ops.top();
                ops.pop();
                int first = vals.top();
                vals.pop();
                int second = vals.top();
                vals.pop();
                int res = evalOp(op, first, second);
                vals.push(res);
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        int first = vals.top();
        vals.pop();
        int second = vals.top();
        vals.pop();
        int res = evalOp(op, first, second);
        vals.push(res);
    }

    return vals.top();
}

int main() {
    string str = "1+2*3*4+3";
    cout << evaluate(str) << endl;

    return 0;
}
