#include <iostream>
#include <list>
using namespace std;

class CompositeList {
public:
    CompositeList(list<list<int> > ll) : l(ll), curIndex(l.begin()->begin()), curList(l.begin()) {}
    bool hasNext() {
        return (curList != l.end());
    }

    int next() {
        int res = *curIndex;
        curIndex++;
        if (curIndex == curList->end()) {
            curList++;
            curIndex = curList->begin();
        }

        return res;
    }

private:
    list<list<int> > l;
    list<int>::iterator curIndex;
    list<list<int> >::iterator curList;
};

int main()
{
    list<list<int> > ll;
    list<int> l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(4);
    list<int> l2;
    l2.push_back(5);
    l2.push_back(1);
    list<int> l3;
    l3.push_back(1);
    l3.push_back(4);
    ll.push_back(l1);
    ll.push_back(l2);
    ll.push_back(l3);
    
    CompositeList cl(ll);
    while (cl.hasNext()) {
        cout << cl.next() << endl;
    }

    return 0;
}
