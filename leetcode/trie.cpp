#include "leetcode.h"
using namespace std;

#define ALPHABET_SIZE 256

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string key) {
            TrieNode* cur = root;
            for (int i = 0; i < key.length(); i++) {
                if (cur->children[key[i]] == NULL)
                    cur->children[key[i]] = new TrieNode();
                cur = cur->children[key[i]];
            }
            cur->isEnd = true;
        }

        bool find(string key) {
            TrieNode* cur = root;
            for (int i = 0; i < key.length(); i++) {
                if (cur->children[key[i]] == NULL)
                    return false;
                cur = cur->children[key[i]];
            }
            return cur->isEnd;
        }

        vector<string> findPrefix(string prefix) {
            vector<string> res;
            TrieNode* cur = root;
            for (int i = 0; i < prefix.length(); i++) {
                if (cur->children[prefix[i]] == NULL)
                    return res;
                cur = cur->children[prefix[i]];
            }

            findPrefixHelp(cur, prefix, res);
            return res;
        }

    private:
        TrieNode* root;
        void findPrefixHelp(TrieNode* root, string& path, vector<string>& res) {
            if (root->isEnd) {
                res.push_back(path);
            } else {
                for (int i = 0; i < ALPHABET_SIZE; i++) {
                    if (root->children[i] != NULL) {
                        path.push_back(i);
                        findPrefixHelp(root->children[i], path, res);
                        path.pop_back();
                    }
                }
            }
        }
};


int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("adobe");
    trie.insert("ball");
    trie.insert("banana");

    vector<string> res = trie.findPrefix("bal");
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
