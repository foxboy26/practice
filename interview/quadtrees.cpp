#include <iostream>
#include <string>
using namespace std;

class QuadTree {
public:
    char type;
    QuadTree* ul;
    QuadTree* ur;
    QuadTree* lr;
    QuadTree* ll;

    QuadTree(char t) : ul(NULL), ur(NULL), lr(NULL), ll(NULL) {
        this->type = t;
    }

    int countBlack() {
        return countBlack(this, 0);
    }

private:
    int countBlack(QuadTree* root, int level) {
        if (root == NULL) return 0;
        if (root->type == 'f') {
            int a = (32 >> level);
            return a * a;
        } else if (root->type == 'e') {
            return 0;
        } else {
            int count = 0;
            count += countBlack(root->ul, level + 1);
            count += countBlack(root->ur, level + 1);
            count += countBlack(root->lr, level + 1);
            count += countBlack(root->ll, level + 1);
            return count;
        }
    }

};

QuadTree* constructFromString(const string& preorder, int& i) {
    if (i == preorder.length()) return NULL;

    QuadTree* qt = new QuadTree(preorder[i]);
    if (qt->type == 'p') {
        i++;
        qt->ul = constructFromString(preorder, i);
        i++;
        qt->ur = constructFromString(preorder, i);
        i++;
        qt->lr = constructFromString(preorder, i);
        i++;
        qt->ll = constructFromString(preorder, i);
    }

    return qt;
}

QuadTree* constructFromString(const string& preorder) {
    int i = 0;
    return constructFromString(preorder, i);
}


QuadTree* add(QuadTree* lhs, QuadTree* rhs) {
    if (rhs == NULL) return lhs;
    if (lhs == NULL) return rhs;

    if (lhs->type == 'f' || rhs->type == 'f') {
        return new QuadTree('f');
    } else if (lhs->type == 'p' || rhs->type == 'p') {
        QuadTree* node = new QuadTree(lhs->type);
        node->ul = add(lhs->ul, rhs->ul);
        node->ur = add(lhs->ur, rhs->ur);
        node->lr = add(lhs->lr, rhs->lr);
        node->ll = add(lhs->ll, rhs->ll);
        return node;
    } else {
        return new QuadTree('e');
    }
}

int main() {
    int T;
    string s1, s2;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> s1 >> s2;
        QuadTree* qt1 = constructFromString(s1);
        QuadTree* qt2 = constructFromString(s2);
        /* cout << qt1->countBlack() << endl; */
        /* cout << qt2->countBlack() << endl; */
        QuadTree* res = add(qt1, qt2);
        cout << "There are " << res->countBlack() << " black pixels." << endl;
    }
}
