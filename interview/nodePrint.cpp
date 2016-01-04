#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    int id;
    int parentId;
    string label;
    Node(int id, int parentId, string label) : id(id), parentId(parentId), label(label) {}
};

unordered_map<int, vector<Node*> > hashTable;

void printNode(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        cout << " ";
    }
    cout << node->label << endl;
    auto neighbour = hashTable[node->id];
    for (int i = 0; i < neighbour.size(); i++) {
        printNode(neighbour[i], level + 1);
    }
}

void print(const vector<Node*>& list)
{
    vector<Node*> roots;
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->parentId != -1) {
            if (hashTable.find(list[i]->parentId) == hashTable.end()) {
                hashTable[list[i]->parentId] = vector<Node*> ();
            }
            hashTable[list[i]->parentId].push_back(list[i]);
        } else {
            roots.push_back(list[i]);
        }
    }


    for (int i = 0; i < roots.size(); i++) {
        printNode(roots[i], 0);
    }
}

int main()
{
    vector<Node*> list;
    list.push_back(new Node(2, -1, "NodeA"));
    list.push_back(new Node(0, 2, "NodeB"));
    list.push_back(new Node(1, 0, "NodeC"));
    list.push_back(new Node(4, -1, "NodeD"));
    list.push_back(new Node(9, 2, "NodeE"));
    list.push_back(new Node(8, 4, "NodeF"));
    list.push_back(new Node(11, -1, "NodeH"));
    list.push_back(new Node(10, 4, "NodeG"));

    print(list);

    for (int i = 0; i < list.size(); i++)
        delete list[i];

    return 0;
}
