#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
using namespace std;

template<class K, class V>
class LRUCache {
    public:
        LRUCache(int capacity) : capacity(capacity) {}
        V get() {}
        void set(K key, V value) {
        }
    private:
        int count;
        int capacity;
        unordered_map<K, list<<pair<K, V> >::iterator> hashTable;
        list<pair<K, V> > l;
};

int main() {
    return 0;
}
