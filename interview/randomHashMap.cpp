#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
using namespace std;

/*
 * key: string
 * val: string
 */
class random_unordered_map {
private:
    unordered_map<string, int> m;
    vector<string> v;
public:
    string find(const string& key) {
        if (m.find(key) != m.end()) {
            return v[m[key]];
        } else {
            return "";
        }
    }

    bool erase(const string& key) {
        if (m.find(key) == m.end()) return false;
        else {
            int idx = m[key];
            swap(v[idx], v[v.size() - 1]);
            v.pop_back();
            m.erase(key);
            return true;
        }
    }

    bool insert(const string& key, const string& value) {
        if (m.find(key) != m.end()) return false;
        else {
            m[key] = v.size();
            v.push_back(value);
            return true;
        }
    }

    string getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

int main()
{
    random_unordered_map m;
    m.insert("a", "apple");
    m.insert("b", "banana");
    m.insert("c", "car");
    m.insert("d", "dog");

    cout << "find: " << m.find("b") << endl;
    cout << "find: " << m.find("c") << endl;

    cout << "randomFind: " << m.getRandom() << endl;
    cout << "randomFind: " << m.getRandom() << endl;

    cout << m.erase("a") << endl;
    cout << m.find("a") << endl;

    cout << "randomFind: " << m.getRandom() << endl;
    cout << "randomFind: " << m.getRandom() << endl;

    return 0;
}

