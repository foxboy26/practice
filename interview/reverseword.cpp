#include <iostream>
#include <cstring>
using namespace std;

void reverse(char str[], int i, int j)
{
    while (i < j)
    {
        swap(str[i++], str[j--]);
    }
}

void reverseword(char str[])
{
    reverse(str, 0, strlen(str)-1);

    int b = 0, e = 0;
    while (str[e] != '\0')
    {
        if (str[e] == ' ')
        {
            reverse(str, b, e-1);
            b = e+1;
        }
        e++;
    }
    reverse(str, b, e-1);

}

int main()
{
    int T;
    char line[1001];

    cin >> T;
    cin.getline(line, 1001);

    for (int t = 0; t < T; t++)
    {
        cin.getline(line, 1001);

        reverseword(line);

        cout << "Case #" << t+1 << ": " << line << endl;
    }

    return 0;
}

