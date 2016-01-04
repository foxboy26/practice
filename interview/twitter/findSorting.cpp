#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

#define ALPHABET_SIZE 26

void buildGraph(vector<string>& dic, int adj[][ALPHABET_SIZE]) {
    int n = dic.size();
    for (int i = 1; i < n; i++) {
        int m = 0, n = 0;
        while (m < dic[i].length() && n < dic[i-1].length()) {
            if (dic[i][m] == dic[i-1][n]) {
                m++;
                n++;
                continue;
            }
            else {
                adj[dic[i-1][n] - 'a'][dic[i][m] - 'a'] = 1;
                break;
            }
        }
    }
}

void tsortHelp(int adj[][ALPHABET_SIZE], int v, bool visited[], stack<int>& s) {
    visited[v] = true;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            tsortHelp(adj, i, visited, s);
        }
    }
    s.push(v);
}

/*
 * The idea is just like we discussed in the interview. We recursive call tsortHelp() to all its childrens.
 * We only push the node into the stack after we traverse all its children.
 * In this way we can get an reverse order where the element in the top is the smallest.
 */
vector<char> tsort(int adj[][ALPHABET_SIZE]) {
    stack<int> s;
    bool visited[ALPHABET_SIZE] = {false};

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (!visited[i]) {
            tsortHelp(adj, i, visited, s);
        }
    }

    vector<char> res;
    while (!s.empty()) {
        res.push_back(s.top() + 'a');
        s.pop();
    }

    return res;
}

int main() {
    vector<string> dic;
    /*dic.push_back("bdag");
    dic.push_back("bge");
    dic.push_back("eac");
    dic.push_back("ei");
    dic.push_back("abc");
    */

    for (int i = 0; i < ALPHABET_SIZE; i++)
        dic.push_back(string(1, i + 'a'));

    int adj[ALPHABET_SIZE][ALPHABET_SIZE] = {0};
    buildGraph(dic, adj);
    vector<char> orders = tsort(adj);

    for (int i = 0; i < orders.size(); i++) {
        cout << orders[i] << " ";
    }
    cout << endl;

    return 0;
}
