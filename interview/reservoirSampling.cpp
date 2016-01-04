#include <iostream>
#include <vector>
using namespace std;

vector<int> sampling(vector<int> pool, int k) {
    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(pool[i]);

    for (int i = k; i < pool.size(); i++) {
        int idx = rand() % (i + 1);
        if (idx >= 0 && idx < k)
            result[idx] = pool[i];
    }

    return result;
}

int main()
{


    return 0;
}
