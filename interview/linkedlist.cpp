#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* constructList(int len)
{
   srand(time(NULL));

   if (len == 0) return NULL;

   ListNode *head = new ListNode(rand()%100);
   ListNode *p = head;
   for (int i = 1; i < len; i++)
   {
       p->next = new ListNode(rand()%100);
       p = p->next;
   }

   return head;
}

void deleteList(ListNode *&head)
{
    ListNode *p;
    while (head)
    {
        p = head;
        delete head;
        head = p->next;
    }
    head = NULL;
}

void print(ListNode *head)
{
    if (head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Empty list" << endl;
    }

    return;
}

void insertFront(ListNode *&head, int x)
{
    if (!head)
    {
        head = new ListNode(x);
    }

    ListNode *newNode = new ListNode(x);

    newNode->next = head;
    head = newNode;
}

void insertBack(ListNode *head, int x)
{
    while (head)
    {
        head = head->next;
    }
    head->next = new ListNode(x);
}

bool isCyclic(ListNode* head)
{
    ListNode *fast, *slow;

    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (!fast || !fast->next)
            return false;

        if (fast == slow || fast->next == slow)
            return true;
    }

    return false;
}

//void reverseDouble(ListNode *&head)
//{
//   if (!head || !head->next) return;
//
//   ListNode *cur = head;
//   while (cur)
//   {
//       swap(cur->next, cur->prev);
//       cur = cur->prev;
//   }
//
//   head = cur->prev;
//
//   return;
//}

void reverse(ListNode *&head)
{
   if (!head || !head->next) return;

   ListNode *prev, *cur, *next;
   prev = NULL;
   cur = head;
   while (cur)
   {
       next = cur->next;
       cur->next = prev;
       prev = cur;
       cur = next;
   }

   head = prev;

   return;
}

void reverseRecursion(ListNode *&head)
{
    if (!head || !head->next) return;

    ListNode *rest = head->next;

    reverseRecursion(rest);

    head->next->next = head;
    head->next = NULL;
    head = rest;
}

void flipPair(ListNode *&head)
{
    if (!head || !head->next) return;

    ListNode *prev, *cur, *next;

    cur = head;
    head = head->next;

    prev = NULL;
    while (cur && cur->next)
    {
        if (prev)
        {
            prev->next = cur->next;
        }
        next = cur->next;
        cur->next = next->next;
        next->next = cur;
        prev = cur;
        cur = cur->next;
    }
}

int main()
{
    ListNode *l = constructList(3);

    print(l);

    reverse(l);

    print(l);

    reverseRecursion(l);

    print(l);

    flipPair(l);

    print(l);

    deleteList(l);

    return 0;
}
