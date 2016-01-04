#ifndef _LEET_CODE__
#define _LEET_CODE__

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

/**
 * Definition for singly linked list
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Debug utilities
 */
void printList(ListNode* head) {
  for (ListNode* l = head; l != NULL; l = l->next) {
    cout << l->val << " ";
  }
  cout << endl;
}

void deleteList(ListNode* head) {
  while (head != NULL) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }
}

void printTreeHelp(TreeNode* root, int level) {
  for (int i = 0; i < level * 2; i++) {
    cout << " ";
  }
  if (root == NULL) {
    cout << "#" << endl;
  } else {
    cout << root->val << endl;
    if (root->left || root->right) {
      printTreeHelp(root->left, level+1);
      printTreeHelp(root->right, level+1);
    }
  }
}

void printTree(TreeNode* root) {
  printTreeHelp(root, 0);
}

void deleteTree(TreeNode* root) {
  if (root) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
  }
}

template<typename T>
void printVector(const vector<T>& v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

#endif
