#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string convert(string str) {
    stringstream ss;
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            if (i != 0)
                ss << '_';
            ss << ((char) tolower(str[i]));
        } else {
            ss << str[i];
        }
    }

    return ss.str();
}

int main() {
    cout << convert("toLower") << endl;
    cout << convert("GetVal") << endl;
    cout << convert("lalalal") << endl;
    cout << convert("LOL") << endl;
    return 0;
}
