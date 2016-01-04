#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define PRECISON 1E-6

static int co = 0;

bool search(vector<double>& num, int n, double target)
{
    if (n == num.size() - 1) {
        co++;
        if (fabs(num[n] - target) <= PRECISON) {
            return true;
        } else {
            return false;
        }
    } else {
        for (int i = n; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                double a = num[i];
                double b = num[j];

                num[j] = a + b;
                if (search(num, n+1, target)) return true;
                num[j] = a - b;
                if (search(num, n+1, target)) return true;
                num[j] = b - a;
                if (search(num, n+1, target)) return true;
                num[j] = a * b;
                if (search(num, n+1, target)) return true;
                num[j] = a / b;
                if (search(num, n+1, target)) return true;
                num[j] = b / a;
                if (search(num, n+1, target)) return true;

                num[i] = a;
                num[j] = b;
            }
        }
        return false;
    }
}

int main()
{
    vector<double> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);

    cout << search(num, 0, 24) << endl;
    cout << "count: " << co << endl;

    return 0;
}
