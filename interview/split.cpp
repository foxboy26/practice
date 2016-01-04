#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string str)
{
    int len = str.length();
    vector<string> res;
    int b = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ' || i == len - 1)
        {
            if (b < i)
                res.push_back(str.substr(b, i-b));
            b = i + 1;
        }
    }

    return res;
}

void print(vector<string> &words)
{
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
}

int main()
{
    string str = "   I'  am a good student.  ";
    string str2 = "";

    cout << str << endl;

    vector<string> words = split(str);

    print(words);

    vector<string> words2 = split(str2);

    print(words2);

    return 0;
}
