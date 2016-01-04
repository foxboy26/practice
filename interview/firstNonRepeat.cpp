#include <iostream>
#include <string>
using namespace std;

char firstNonRepeated(string str)
{
    int count[256];

    for (int i = 0; i < 256; i++) count[i] = 0;

    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] == 1) return str[i];
    }

    return str[0];
}

int main()
{
    string str = "sfsfagawewdsa";

    cout << firstNonRepeated(str) << endl;
}
