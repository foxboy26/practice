#include <iostream>
#include <string>
using namespace std;

bool isomorphic(string a, string b)
{
    int mapping[256];
    for (int i = 0; i < 256; i++) mapping[i] = -1;

    int len = a.length();
    for (int i = 0; i < len; i++)
    {
        if (mapping[a[i]] == -1)
            mapping[a[i]] = b[i];
        else {
            if (mapping[a[i]] != b[i]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cout << (isomorphic("app", "foo") && isomorphic("foo", "app")) << endl;
    return 0;
}
