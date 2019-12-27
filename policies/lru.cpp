#include "lru.hpp"

void lru::evict(uint64_t id) {
    auto cm_it = cm.find(id);
    if (cm_it != cm.end()) {
        auto ll_it = cm_it->second;
        usage -= ll_it->second;

        ll.erase(ll_it);
        cm.erase(cm_it);
    }
}

void lru::evict() {
    // find last
    auto ll_it = ll.end();
    --ll_it;
    
    // decrement size
    usage -= ll_it->second;

    cm.erase(ll_it->first);
    ll.erase(ll_it);
}

bool lru::get(uint64_t id) {
    auto it = cm.find(id);
    if (it != cm.end()) {
        hit(it->second);
        return true;
    }
    return false;
}

void lru::set(uint64_t id, size_t size) {
    if (size >= threshold)
        return;
    
    while (usage + size > capacity)
        evict();

    // admit new object
    ll.push_front(std::make_pair(id, size));
    cm[id] = ll.begin();
    usage += size;
}

void lru::hit(lru_list::iterator it) {
    ll.splice(ll.begin(), ll, it);
}
