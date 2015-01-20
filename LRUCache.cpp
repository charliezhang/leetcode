#include<list>
#include<map>
using namespace std;
class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = _cache.find(key);
        if (it == _cache.end()) {
            return -1;
        }
        _refresh(key);
        return it->second;
    }
    
    void set(int key, int value) {
        if (_capacity == 0) {
            return;
        }
        auto it = _cache.find(key);
        if (it != _cache.end()) {
            keys.erase(_positions[key]);
        } else if (keys.size() == _capacity) {
            _evict();
        }
        _cache[key] = value;
        keys.push_back(key);
        auto last = keys.end();
        _positions[key] = --last;
    }

    void _refresh(int key) {
        keys.erase(_positions[key]);
        keys.push_back(key);
        auto last = keys.end();
        _positions[key] = --last;
    }
    
    void _evict() {
        auto it = keys.front();
        keys.pop_front();
        _cache.erase(it);
        _positions.erase(it);
    }
    
private:
    int _capacity;
    map<int, int> _cache;
    map<int, list<int>::iterator> _positions;
    list<int> keys;
};

int main() {
}
